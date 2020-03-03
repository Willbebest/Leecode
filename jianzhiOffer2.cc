/**********************************************************
* 题目描述： 
* 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，
* 当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy
************************************************************/

void replaceSpace(char *str,int length) {
	if(str==NULL&&length==0)
		return;
	int spaceNum=0;
	int Num=0;
	char *s=str;
	while(*str){
		if(*str==' ')
			spaceNum++;
		Num++;
		str++;
	}
	if(spaceNum==0)
		return;
	str=s;
	int newlength=Num+2*spaceNum;
	if(newlength>=length)
		return;
	while(Num>=0){
		if(s[Num]==' '){
			s[newlength--]='0';
			s[newlength--]='2';
			s[newlength--]='%';
		}
		else
			s[newlength--]=s[Num];
		Num--;
	}
	return;
}