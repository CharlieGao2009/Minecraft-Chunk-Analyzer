#include<bits/stdc++.h>
#include<fstream>
using namespace std;
char Data[900100];
unsigned short a[900100];
int main()
{
	ifstream file("first4K.sample",ios::binary|ios::in|ios::ate);
	ifstream::pos_type n=file.tellg();
	cout<<n<<endl;
	file.seekg(0);
	file.read((char*)(&Data),n);
	Data[n]='\0';
	file.close();
	string s(Data);
	for (int i=0;i<s.size();i++)
		a[i+1]=int(s[i]);
	for (int i=1;i<=n;i++)
		cout<<i<<' '<<a[i]<<endl;
	return 0;
}
