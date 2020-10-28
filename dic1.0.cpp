#include <iostream> 
using namespace std;
#include <fstream> 
#include<string>
#include<conio.h>
#include<stdio.h>
#include<windows.h> 
class dictionary
{
	int Id;
	string Tu; 
	public:
		dictionary();
		dictionary(int id, string tu); 
		int getId();
		string getTu(); 
		void setId(int new_id){
			Id=new_id; 
		} 
		void printTu(){
			cout<<Id<<endl<<Tu<<endl;
	}
};

dictionary::dictionary() 
{
	Id=-1; 
	Tu=""; 
}

dictionary::dictionary(int id, string tu)
{
	dictionary();
	this->Id=id; 
	this->Tu=tu; 
}

int dictionary::getId()
{
	return Id;	
} 

string dictionary::getTu() 
{
	return Tu; 
} 

class T_M_E:public dictionary
{ 
	string loaiTu;
	string Nghia;
	string viDu; 
	public:
		T_M_E();
		T_M_E(string, string, string);
		T_M_E(int, string, string, string, string);
		void xuatTu(){
			this->printTu();
			cout<<loaiTu<<endl<<Nghia<<endl<<viDu<<endl; 
		}
};

T_M_E::T_M_E(int id, string tu, string Ty, string Me, string Ex):dictionary(id, tu)
{
	this->loaiTu=Ty;
	this->Nghia=Me;
	this->viDu=Ex; 
} 

int main() {	 
	ifstream fw,ft,fm,fe; 
	fw.open("word.txt", ios::in);
	ft.open("type.txt", ios::in);
	fm.open("mean.txt", ios::in);
	fe.open("example.txt", ios::in);
	string tu, loai, nghia, vd; 
	char key;
	int count=0;
	while (!fw.eof())
	{ 
		getline(fw, tu, ' ');
		count++; 
		getline(ft, loai, ' ');
		getline(fm, nghia, '@');
		getline(fe, vd, '@'); 
		T_M_E tuVung(count,tu,loai,nghia,vd);
		tuVung.xuatTu();		 
	}
	fw.close();
	ft.close();
	fm.close();
	fe.close();
	return 0;
}
