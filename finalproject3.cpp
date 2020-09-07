#include<bits/stdc++.h>


using namespace std;
pair<string,string> modify[200];
bool need[200];
string h1="";
string h2="";
string st;
int satr = 0;
int skip = 0;
int flag = 0;
int p=0;
int sum = 0;
bool isprinted[200];
map<string,string> type34;
map<string,string> type2;
map<string,string> atable;
pair<string,string> ltable[200];
pair<string,string> ltable2[200];
int ltc=0;

int length[200];
pair <string,string> line[200];
string st3[200];

void fill() //fill with instruction set
{
	type34["ADD"]="18";
	type34["AND"]="40";
	type34["COMP"]="28";
	type34["DIV"]="24";
	type34["J"]="3C";
	type34["JEQ"]="30";
	type34["JGT"]="34";
	type34["JLT"]="38";
	type34["JSUB"]="48";
	type34["LDA"]="00";
	type34["LDB"]="68";
	type34["LDCH"]="50";
	type34["LDL"]="08";
	type34["LDS"]="6C";
	type34["LDX"]="04";
	type34["LDT"]="74";
	type34["MUL"]="20";
	type34["OR"]="44";
	type34["RD"]="D8";
	type34["RSUB"]="4C";
	type34["STA"]="0C";
	type34["STCH"]= "54";
	type34["STL"]="14";
	type34["STSW"]="E8";
	type34["STX"]="10";
	type34["SUB"]="1C";
	type34["TD"]="E0";
	type34["TIX"]="2C";
	type34["WD"]="DC";
	
	type2["ADDR"]="90";
	type2["CLEAR"]="B4";
	type2["COMPR"]="A0";
	type2["DIVR"]="9C";
	type2["TIXR"]="B8";
	
	
}

string forname(string s) //make name 6
{
	string s2="";
	
	for(int i=0;i<6-s.length();i++)
	s2 += "X";
	
	return s+s2;
}



string decimaltohex(int x)
{
	std::stringstream ss;
	ss<< std::hex << x; // int decimal_value
	std::string res ( ss.str() );

	return res;
	
	
}

string sumofchar(string s)
{
	string sum="";
	for(int i=3;i<s.length()-1;i++)
	sum+=decimaltohex(s[i]);
	
	return sum;
}

int hextodecimal (string s)
{
	
	
	
	int x;
	
	
	std::stringstream ss;
	ss  << s ; // std::string hex_value
	ss >> std::hex >> x ; //int decimal_value

	
	
	return x;
}

int stringtodecimal(string s)
{
	int z;
	std::istringstream iss (s);
	iss >> z;
	
	return z;
}

string make4(string s) //makelength4
{
	if(s.length() >= 4)
	return s;
	else if(s.length() == 1)
	return "000"+s;
	else if(s.length() == 2)
	return "00"+s;
	else if(s.length() == 3)
	return "0"+s;
	
	
}

string make5(string s) 
{
	if(s.length() >= 5)
	return s;
	else if(s.length() == 1)
	return "0000"+s;
	else if(s.length() == 2)
	return "000"+s;
	else if(s.length() == 3)
	return "00"+s;
	else if(s.length() == 4)
	return "0"+s;
	
	
	
}

string make6(string s) 
{
	if(s.length() == 6)
	return s;
	else if(s.length() == 1)
	return "00000"+s;
	else if(s.length() == 2)
	return "0000"+s;
	else if(s.length() == 3)
	return "000"+s;
	else if(s.length() == 4)
	return "00"+s;
	else if(s.length() == 5)
	return "0"+s;
	
	
	
}

string eqn(string s)
{
	int val = 0;
	int f = 1;
	string op = "";
	int adder;
	
	for(int i=0;i<s.length();i++)
	{
		if(i == s.length() - 1)
		{
			op = op + s[i];
			if( atable.find(op) != atable.end() )
			adder = hextodecimal (atable[op]);
			else
			adder = stringtodecimal(op);
			
			if(f)
			val = val + adder;
			else
			val = val - adder;
		}
		else
		{
			if(s[i] == '-')
			{
				if( atable.find(op) != atable.end() )
				adder = hextodecimal (atable[op]);
				else
				adder = stringtodecimal(op);
				
				
				if(f)
				val = val + adder;
				else
				val = val - adder;
				
				f=0;
				op="";
				
			}
			else if(s[i] == '+')
			{
				if( atable.find(op) != atable.end() )
				adder = hextodecimal (atable[op]);
				else
				adder = stringtodecimal(op);
				
				if(f)
				val = val + adder;
				else
				val = val - adder;
				
				f=1;
				op="";
			}
			else
			op = op + s[i];
		}
		
		
	}
	
	return decimaltohex(val);
}

string make3(string s) //makelength3
{
	if(s.length() >= 3)
	return s;
	else if(s.length() == 1)
	return "00"+s;
	else if(s.length() == 2)
	return "0"+s;
	
}

string make2(string s) //makelength2
{
	if(s.length() >= 2)
	return s;
	else if(s.length() == 1)
	return "0"+s;

	
}

string operation (string dst , string source) //subtract two hexa numbers
{
	string ans = decimaltohex(hextodecimal(dst) - hextodecimal(source));
	if(hextodecimal(dst) < hextodecimal(source))
	return ans.substr(5,3);
	else
	return (ans);
}

string addhexa1 (string op1,string op2) //add hexa and hexa
{
	return decimaltohex(hextodecimal(op1)  + hextodecimal(op2));
}

string addhexa2 (string op1,int op2) //add hexa and decimal
{
	return decimaltohex(hextodecimal(op1)  + (op2));
}

bool rel(string s1) 
{
	int plus = 1;
	int minus = 0;
	
	if(s1.find('+') == std::string::npos && s1.find('-') == std::string::npos )
	{
		if( atable.find(s1) != atable.end() )
		return 1; //like BUFFER
		else
		return 0; //like 3000
	}
	
	for(int i=0;i<s1.length()-1;i++)
	{
		if(s1[i] == '+' && (s1[i+1] >= 'A' && s1[i+1] <= 'Z' ) )
		plus++;// a positive label
		else if(s1[i] == '-' && (s1[i+1] >= 'A' && s1[i+1] <= 'Z' ) )
		minus++; //a negative label
	}
	
	return (plus > minus);//if so, its relative
}

string numtostring(int num)
{
	
	ostringstream str1; 
  
    // Sending a number as a stream into output 
    // string 
    str1 << num; 
  
    // the str() coverts number into string 
    string geek = str1.str(); 
	
	return geek;
}


int main()

{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
		
	fill();
	string literal[200];
	string s1,s2,s3,curr,address[200];
	string pname,test;
	string start;
	//string end;
	string opcode[200];
	string wanted;
	string part1,part2,part3;
	string x;
	string temp;
	int mid=0;
	int adder,z;
	string base;
	int c=0;
	//atable["WRREC"] = "105d";
	
	cout<<"Location Counter"<<endl;
	
	
	while(s1 != "End")
	{
		cin>>s1;
		if ( type34.find(s1) != type34.end() ) //is S1 an instruction of type 3? 
		{
			if(s1 != "RSUB")
			{
				length[c] = 2;
				cin>>s2;
			}
			else
			length[c] = 1;
  			
  			
  			adder = hextodecimal(curr);
  			adder = adder + 3;
  			
  			
  			
  			line[c].first = s1; 
  			line [c].second = s2;
  			
  			
  			
		}
		else if ( s1.find('+') != std::string::npos ) //is S1 an instruction of type 4? 
		{
  			cin>>s2;
  			
  			adder = hextodecimal(curr);
  			adder = adder + 4;
  			
  			
  			
  			line[c].first = s1; 
  			line [c].second = s2;
  			length[c] = 2;
  			
  			
		}
		else if ( type2.find(s1) != type2.end() ) //is S1 an instruction of type 2? 
		{
  			cin>>s2;
  			
  			adder = hextodecimal(curr);
  			adder = adder + 2;
  			
  			
  			
  			line[c].first = s1; 
  			line [c].second = s2;
  			length[c] = 2;
  			
  			
		}
		else if(s1 == "LTORG") 
		{
			cout<<"LTORG"<<endl;
			
			for(int i=0;i<ltc;i++)
			{
				isprinted[i] = true;
				address[c] = make4(curr);
				cout<<make4(curr) <<" *"<<" "<<literal[i]<<endl;
				atable[literal[i]] = make4(curr);
				adder = hextodecimal(curr);
				line[c].first = "*"; 
  				line [c].second = literal[i];
  				length[c] = 2;
  				
  				c++;
  				
  				
			}
			
			if(s2[1] == 'X')
  			{
  				adder += (s2.length()-4)/2;
  				ltable2[ltc].first = decimaltohex( (s2.length()-4)/2 );
  				ltable2[ltc].second = make4(curr);
  				ltable[ltc].second = (s2);
			}
			
			else
			{
				adder += (s2.length()-4);
				ltable2[ltc].first = decimaltohex(s2.length()-4);
				ltable2[ltc].second = make4(curr);
				ltable[ltc].second = sumofchar(s2);
			}
			
			curr = decimaltohex(adder);
			
			ltable[ltc].first = s2;
		}
		else if(s1 == "BASE")
		{
			cin>>s2;
			base = s2;
			//cout<<"-"<<endl;
			
			line[c].first = s1; 
  			line [c].second = s2;
  			length[c] = 2;
		}
		else if(s1 == "End") //End
		{
			cin>>s2;
  			
  			line[c].first = s1; 
  			line [c].second = s2;
  			length[c] = 2;
  			atable[s1] = curr;
		}
		
		
		else //here, we surely have a length of 3. S1 is some sort of label or variable
		{
			
			cin>>s2;
			cin>>s3;
			
			line[c].first = s1;
  			line [c].second = s2;
  			st3[c] = s3;
  			length[c]=3;
			
			
			if(s2 == "Start") //save name
  			{
  				pname=s1;
  				curr = s3;
			}
			
			
			if ( type34.find(s2) != type34.end() ) //is S2 an instruction of type 3? 
			{
  			
  			
  			adder = hextodecimal(curr);
  			adder = adder + 3;
  	
  			
			}
			else if ( s2.find('+') != std::string::npos ) //is S2 an instruction of type 4? 
			{
  			
  			
  			adder = hextodecimal(curr);
  			adder = adder + 4;
  	
  			
  						
			}
			else if ( type2.find(s2) != type2.end() ) //is S2 an instruction of type 2? 
			{
  			
  			
  			adder = hextodecimal(curr);
  			adder = adder + 2;
  		
  			
			}
			
			else if(s2 == "EQU")
			{
				if(s3 == "*")
				temp = curr;
				else
				temp = eqn(s3);
				
				
				atable[s1] = temp;
				
				
			}
			
			else// it is RESW or Byte or RESB or Word
			{
				adder = hextodecimal(curr); //integer value of current
				if(s2 == "RESW" || s2 == "RESB" )
				{
					z = stringtodecimal(s3); //z is integer value of s3
					
					
					
				}
				
				
				if(s2 == "RESB")
				adder += z;
				else if(s2 == "BYTE")
				{
					if(s3[0] == 'X')
					adder += (s3.length()-3)/2;
					else
					adder += (s3.length()-3);
				}
				
				else if(s2 == "RESW")
				adder += (z*3);
				else //word
				adder += 3;
				
				
				//cout<<"**";
				//curr = decimaltohex(adder);
			}
			
			
		
	 		//cout<<"**"<<s1<<" "<<s2<<" "<<s3<<endl;
			
			if(s2 != "EQU")
			atable[s1] = make4(curr);
			
		}
			
			if(s1 != "LTORG")
			address[c]=make4(curr);
			
			if( s2.find('=') != std::string::npos && length[c] == 2)
			{
				literal[ltc] = s2;
				ltc++;
			}
			
			if( s3.find('=') != std::string::npos && length[c] == 3)
			{
				literal[ltc] = s3;
				ltc++;
			}
			
			
			
			if(length[c] == 2)
			cout<<address[c]<<" "<<s1<<" "<<s2<<endl;
			else if(length[c] == 3 && s2 != "EQU")
			cout<<address[c]<<" "<<s1<<" "<<s2<<" "<<s3<<endl;
			else if(length[c] == 3 && s2 == "EQU")
			cout<<make4(temp)<<" "<<s1<<" "<<s2<<" "<<s3<<endl;
			else
			cout<<address[c]<<" "<<s1<<endl;
	 	
			if(s2 != "Start")
			curr = decimaltohex(adder);
			
			if(s1 != "LTORG" && s1 != "BASE")
			c++;
			
			//cout<<ltc<<endl;
		
	}
	
	int mx = c-1;
	string end = address[c-1];
	
	for(int i=0;i<ltc;i++)
	{
		
		if(!isprinted[i])
		{
			atable[literal[i]] = make4(end);
			s1 = literal[i];
			cout<< make4(end)<<" *   " <<literal[i]<<endl;
			
			if(s1[1] == 'C')
			opcode[c-1] = sumofchar(s1);
			else
			opcode[c-1] = s1.substr(3,s1.length() - 4);
			
			//line[c].first = "*"; 
  			//line [c].second = literal[i];
  			//length[c] = 2;
			
			cout<<c<<"   "<<opcode[c-1]<<endl;
			mx++;
		}
	} 
	
	
	cout<<endl;
	cout<<"Symbol Table"<<endl;
	
	map<string, string>::iterator it;
	
	for ( it = atable.begin(); it != atable.end(); it++ )
	{
		if( it->first != "End" )
		cout<<it->first<<" "<<it->second<<endl;;
		
	}
	
	cout<<endl<<endl;
	
/*	if(ltc > 0)
	{
		cout<<"Literal Table"<<endl;
		//cout<<"Name"<<"            "<<"Value"<<"      "<<"Size"<<"    "<<"Address"<<endl;
	
	for(int i=0;i<ltc;i++)
	{
		cout<<ltable[i].first<<"    "<<ltable[i].second<<"      "<<ltable2[i].first<<"    "<<ltable2[i].second<<endl;
	}
	
	
	OPCODES
	
	
	} */
	
	for(int i=1;i<mx;i++)//mx is number of lines
	{
		mid = 0;//mid is xbpe
		if(length[i] == 1)//RSUB corner case
		{
			s1 = line[i].first;
			
			
			if(s1 == "RSUB")
			opcode[i]="4f0000";
			
			cout<<opcode[i]<<endl;
			 
		}
		else if(length[i] == 2)//instructions of length 2
		{
			s1 = line[i].first;
			s2 = line[i].second;
			
			if( s2.find('@') != std::string::npos ) // is it indirect?
			{
				adder = 2; //adder is ni
				s2 = s2.substr(1 , s2.length() - 1);
			}
			else if( s2.find('#') != std::string::npos )  // is it immediate?
			{
				adder = 1;
			}
			else
			{
				adder = 3;
			}
			
			
			
			if( s2.find(',') != std::string::npos && type34.find(s1) != type34.end())//if there is a x in s2
			{
				s2 = s2.substr(0,s2.length()-2);
				mid += 8;
			}
			
			if( atable.find(s2) != atable.end() )//s2 is a variable
			{
				
				part3 = operation(atable[s2] , address[i+1]); //operation subtract 2 numbers
				
				if( type34.find(s1) != type34.end() ) //try PC relative
				{
					if(part3.length() <= 3)
					{
						part3=make3(part3);
						mid+=2;
					}
					
					else //if not, try Base relative
					{
						part3 = make3(operation(atable[s2] , atable[base]));
						mid+=4;	
					}
				}
			}
			
			
			else if( s2.find('#') != std::string::npos ) //this is an immediate
			{
				
				s2 = s2.substr(1 , s2.length() - 1);
				
				if( atable.find(s2) != atable.end() )//immediate label like #BUFFER
				{
					part3 = (atable[s2]);
					part3 = make3(operation(atable[s2] , address[i+1]));
					mid+=2;
				}
				
				else //immediate number like #300
				part3 = make3(decimaltohex (stringtodecimal(s2)));
			}
			
			else if( ( s1.find('+') == std::string::npos ) && ( type2.find(s1) == type2.end() )  ) //this is like LDA 1000
			{
				
				
				mid=0;
				part3 = make3(decimaltohex (stringtodecimal(s2)));
				need[i] = 1;
				modify[i].first = make6( addhexa2(address[i],1) );
				modify[i].second = "000003";
			}
			
			
			
			
			if( type34.find(s1) != type34.end() )//is S1 an instruction of type 3? 
			part1 = decimaltohex(hextodecimal(type34[s1]) + adder);
			else if ( s1.find('+') != std::string::npos ) //is S1 an instruction of type 4? 
			{
				part1 = decimaltohex(hextodecimal(type34[s1.substr(1,s1.length() - 1)]) + adder);
				part3 = make5(eqn(s2)); //evaluate the equation in S2
				mid++; //e = 1
				
				
					if(rel(s2)) //is it relative? if so, modify
					{
					need[i] = 1;
					modify[i].first = make6( addhexa2(address[i],1) );
					modify[i].second = "000005";
					}
				
			}
			else if ( type2.find(s1) != type2.end() ) //is S2 an instruction of type 2?
			{
				part1 = type2[s1];

				if(s2[0] == 'X')
				part2="1";
				else if(s2[0] == 'S')
				part2="4";
				else if(s2[0] == 'T')
				part2="5";
				else if(s2[0] == 'A')
				part2="0";
				
				if(s2.length() == 1)
				part3="0";
				else if(s2[2] == 'X')
				part3="1";
				else if(s2[2] == 'S')
				part3="4";
				else if(s2[2] == 'T')
				part3="5";
				else if(s2[2] == 'A')
				part3="0";
			}
			
			
		    if (!( type2.find(s1) != type2.end() ))//convert mid to hexa , if its not type 2
			part2 = decimaltohex(mid);
			
			
			
			opcode[i] = make2(part1)+part2+part3;//part 1 is object code + ni  , part 2 is xbpe, part 3 is displacement
			
			if(s1 == "*") //literals
			{
				if(s2[0] = 'C')
				opcode[i] = sumofchar(s2);
				else
				opcode[i] = s2.substr(3,s2.length() - 4);
			}
			
			
			cout<<s1<<" "<<s2<<endl;
			cout<<opcode[i]<<endl;
			
		}
		else
		{
			mid = 0;
			s1 = line[i].first;
			s2 = line[i].second;
			s3 = st3[i];
			//cout<<s3<<"***"<<endl;
			
			
			if( type34.find(s2) != type34.end() )//same like above but if its length 3
			{
				
				if( s3.find(',') != std::string::npos)//if there is a x
				{
					s3 = s3.substr(0,s3.length()-2);
					mid += 8;
				}
				part1 = addhexa2(type34[s2],3);
				part3 = operation(atable[s3] , address[i+1]);
			
					if(part3.length() <= 3)
					{
						part3=make3(part3);
						mid+=2;
					}
					
					else
					{
						part3 = make3(operation(atable[s2] , atable[base]));
						mid+=4;	
					}
					
					
					part2 = decimaltohex(mid);
					opcode[i] = make2(part1)+part2+part3;
			
		
					
					
			}
			
			else if( s2.find('+') != std::string::npos )
			{
				mid += 1;
				part1 = addhexa2(type34[s2.substr(1,s2.length() - 1)],3);
				part3 = make5(atable[s3]);
				part2 = decimaltohex(mid);
				opcode[i] = make2(part1)+part2+part3;
			}
			
			else if( type2.find(s2) != type2.end() )
			{
				part1 = type2[s2];
				
				if(s3[0] == 'X')
				part2="1";
				else if(s3[0] == 'S')
				part2="4";
				else if(s3[0] == 'T')
				part2="5";
				else if(s3[0] == 'A')
				part2="0";
				
				if(s3.length() == 1)
				part3="0";
				else if(s3[2] == 'X')
				part3="1";
				else if(s3[2] == 'S')
				part3="4";
				else if(s3[2] == 'T')
				part3="5";
				else if(s3[2] == 'A')
				part3="0";
				
				opcode[i] = make2(part1)+part2+part3;
			}
			
			
			else if(s2 == "EQU") //no opcode code for equate
			{
				opcode[i] = "-";
				
				
			}
			else if(s2 == "BYTE") //byte , just put the data
			{
				if(s3[0] == 'X')
				opcode[i] = s3.substr(2 , s3.length() - 3);
				else
				opcode[i] = sumofchar(s3);
			}
			else if(s2 == "WORD") //word convert to hexa
			{
				opcode[i] = make6(decimaltohex(hextodecimal (s3)));
				
				
				
			}
			else //RESW, RESB no opcode
			{
				opcode[i] = "-";
			}
				
			cout<<s1<<" "<<s3<<endl;
			cout<<opcode[i]<<endl;
			}
			
			
			
		}
		
		cout<<endl;
		
		cout<<endl<<"HTE record"<<endl;
	
	   	cout<<"H."<<forname(pname)<<"."<<make6(atable[pname])<<"."<<  make6 (decimaltohex (hextodecimal(atable["End"]) - hextodecimal((atable[pname]) )))<<endl;
		
		for(int i=1;i<mx;i++)
	{
		if(opcode[i] == "-")
		{
			flag = 1;
			skip++;
			
			
			
			
		}
		else
		{
			flag = 0;
			p=0;
			skip=0;
			h2+=opcode[i]+"  .";
			satr++;
			sum = sum + (hextodecimal(address[i+1])-hextodecimal( address[i]   ));
			
			if(satr == 1)
			st=address[i];
		}
		
		if(flag == 1 && skip == 1 && p == 0)
		{
			
			h1="T. "+make6(st)+"  ."+make2(decimaltohex(sum))+"  .";
			cout<<h1<<h2<<endl;		
			h1="";
			h2="";	
			satr=0;
			sum=0;
			
		}
		else if(satr == 10 && p == 0)
		{
			p=1;
			h1="T. "+make6(st)+"  ."+make2(decimaltohex(sum))+"  .";
			cout<<h1<<h2<<endl;	
			h1="";
			h2="";
			satr=0;
			sum=0;
		}
		else if(i == c-2 && flag == 0 && p == 0)
		{
			p=1;
			h1="T. "+make6(st)+"  ."+make2((decimaltohex(sum)))+"  .";
			cout<<h1<<h2<<endl;	
			h1="";
			h2="";	
			satr=0;
			sum=0;
		}
		
		
		
	}
	
	for(int i=1;i<mx;i++)
	{
		if(need[i])
		cout<<"M. "<<modify[i].first<<" ."<<modify[i].second<<endl;
	}
	
	cout<<"E. "<<make6(atable[pname])<<endl;
	cout<<numtostring(15);


}
