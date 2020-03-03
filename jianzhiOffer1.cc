/**********************************************************
* 问题描述
* 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左
* 到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完
* 成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否
* 含有该整数
************************************************************/

bool Find(int target, vector<vector<int> > array) {
	bool ret=false;
	if(array.empty())
		return false;
	int x=array.size();
	int y=array[0].size();
	int i=0,j=y-1;
	while(i<x&&j>=0)
	{
		if(array[i][j]==target)
		{
			ret=true;
			break;
		}
		else if(array[i][j]<target)
			i++;
		else
			j--;
	}
	
	return ret;
}