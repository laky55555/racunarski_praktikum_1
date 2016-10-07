#include <iostream>
#include <string>
#include <list>

using namespace std;

char ggg[4] = { 'A', 'C', 'G', 'T' };

class Populacija;

class Jedinka
{
public:
	string geni;
	Populacija *p;
	Jedinka( string _geni = "" ) { geni = _geni; p = NULL; }
	
	char& operator[]( int index )
	{
		while( geni.size() <= index )
		    geni += 'A';
		    
		return geni[index];
	}
};

class Populacija
{
public:
	list<Jedinka *> popis;
};

ostream& operator<<( ostream &f, Populacija &p )
{
	for( list<Jedinka *>::iterator li = p.popis.begin(); li != p.popis.end(); ++li )
	    f << (*li)->geni << " ";
	    
	return f;
}

void operator<<( Populacija &p, Jedinka &j )
{
	for( list<Jedinka *>::iterator li = p.popis.begin(); li != p.popis.end(); ++li )
	    if( *li == &j )
	        return;

	p.popis.push_back( &j );
	j.p = &p;
}

void operator>>( Populacija &p, Jedinka &j )
{
	for( list<Jedinka *>::iterator li = p.popis.begin(); li != p.popis.end(); ++li )
	    if( *li == &j )
	    {
			p.popis.erase( li );
			j.p = NULL;
	        return;
		}
}

Jedinka operator+( const Jedinka &j1, const Jedinka &j2 )
{
	Jedinka nova;
	
	if( j1.p != j2.p || j1.geni.size() != j2.geni.size() )
	    return nova;
	    
	for( int i = 0; i < j1.geni.size(); ++i )
	    nova.geni += ( i % 2 == 0 ) ? j1.geni[i] : j2.geni[i];
	    
	return nova;
}

Jedinka operator!( const Jedinka &j )
{
	Jedinka nova;
	
	for( int i = 0; i < j.geni.size(); ++i )
	    if( i % 2 )
	    {
			int zz = rand() % 4;
			nova.geni += ggg[zz];
		}
		else
		    nova.geni += j.geni[i];
		    
	return nova;
}


int main( void )
{
    Jedinka slon, slonica( "CCTAG" ), mis( "CC" );
        // konstruktor može primiti string koji je niz gena
        // dakle: slon="", slonica="CCTAG", mis="CC"

	Populacija krdo, jato;
        // konstruktor ne prima ništa, krdo je prazno, jato je prazno

	slonica[3] = 'G'; // mijenja 3. gen od slonice u G --> slonica = "CCTGG"
	slon[2] = 'C';    // 2. gen od slona je 'C'; 0. i 1. postavlja bilo kako, npr. slon="AAC"
	slon[4] = 'T';    // 4. gen od slona je 'T'; 3. postavlja bilo kako, npr. slon="AACAT"

	krdo << slonica;  // slonica ulazi u krdo: krdo = ( slonica )
	krdo << slon;     // slon ulazi u krdo: krdo = ( slonica, slon )
	cout << krdo << endl;     // ispisuje "AACAT CCTGG" u bilo kojem redoslijedu

	Jedinka dambo, mislonica, novi;
	dambo = slon + slonica;
        // krizanjem slona i slonice nastaje dambo; parne gene dobiva od slona
        // a neparne od slonice: dambo = "ACCGT"; dambo nije ni u jednoj populaciji

	krdo << mis;      // krdo = ( slonica, slon, mis )
	mislonica = mis + slonica;
        // nemaju isti broj gena pa se ne krizaju, mislonica=""

	cout << krdo << endl;     // ispisuje "AACAT CCTGG CC" u bilo kojem redoslijedu
	krdo >> slon;             // slon izlazi iz krda, krdo = ( slonica, mis );
	cout << krdo << endl;     // ispisuje "CCTGG CC"

	novi = slon + slonica;
        // nema krizanja jer nisu u istoj populaciji, dakle novi=""
        // Ako ne znate ovo implementirati, stavite novi="ACCGT" kao ranije

	dambo = !dambo;   // dambo mutira tako da mu se parni geni promijene bilo kako,
                      // npr. dambo="TCGGA"
	jato << dambo;    // dambo ulazi u jato
	cout << jato << endl;     // ispisuje "TCGGA"

	return 0;
}
