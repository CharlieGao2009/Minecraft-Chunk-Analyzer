#include<bits/stdc++.h>
#include<fstream>
using namespace std;
char DataRaw[4100];
uint8_t DataUnsigned8[4100];
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
	for (int i=1;i<=n;i++)
		cout<<i<<' '<<+DataUnsigned8[i]<<endl;
	return 0;
}
