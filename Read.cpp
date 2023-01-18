#include<bits/stdc++.h>
#include<fstream>
using namespace std;
char DataRaw[4100];
uint8_t DataUnsigned8[4100];
struct F4K{int pos,sz,dfn;} _chunk[40][40];
int main()
{
	ifstream file("first4K.sample",ios::binary|ios::in|ios::ate);
	ifstream::pos_type n=file.tellg();
	freopen("offset.out","w",stdout);
	file.seekg(0);
	file.read((char*)(&DataRaw),n);
	DataRaw[n]='\0';
	file.close();
	string s(DataRaw);
	for (int i=0;i<s.size();i++)
		DataUnsigned8[i+1]=uint8_t(s[i]);
	for (int i=0;i<32;i++)
	{
		for (int j=0;j<32;j++)
		{
			int id=4*((i&31)+(j&31)*32);
			_chunk[i][j].pos=(DataUnsigned8[id+3]<<16)+(DataUnsigned8[id+2]<<8)+DataUnsigned8[id+1];
			_chunk[i][j].sz=DataUnsigned8[id+4];
		}
	}
	for (int i=0;i<32;i++)
	{
		for (int j=0;j<32;j++)
			cout<<i<<' '<<j<<' '<<_chunk[i][j].pos<<' '<<_chunk[i][j].sz<<endl;
	}
	return 0;
}
