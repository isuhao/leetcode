//runtime 172ms farm animals
class Solution {
public:
    string convert(string s, int numRows) {
		if(numRows<2)
			return s;
        //nums of char each box contains
		int k = numRows*2 - 2;
		int length = s.size();
		//����ȡ��
		int numBoxes = (length + k -1) / k; 
		vector<vector<char>> box;
		box.resize(numRows, vector<char>(numBoxes*(numRows-1),0));

		int mark = 0;
		for(int i=0; i<numBoxes; i++){
			for(int j=i*k; j<length&&j<(i+1)*k;){
				//����1
				for(int p=0; j<length&&p<numRows; p++){
					box[p][i*(numRows-1)]=s[j++];
				}
				//�Խ���
				for(int q=numRows-2; j<length&&q>0; q--){
					box[q][numRows-1-q+i*(numRows-1)]=s[j++];
				}
			}
		}
		string b;
		for(int m=0; m<numRows; m++){
			for(int n=0; n<(numRows-1)*numBoxes; n++){
				if(box[m][n]!=0)
					b.push_back(box[m][n]);
			}
		}
		return b;
    }
};