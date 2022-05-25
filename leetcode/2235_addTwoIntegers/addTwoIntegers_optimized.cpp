class Solution {
public:
    int sum(int x,int y){
     if (y == 0)
        return x;
	 else if (x < 0 && y < 0){
		int add = ~x^~y;
		int carry = (~x &~y)<<1;
		return ~sum(sum(add,carry),1);
	 }
	else{
		int add = x^y;
		int carry = (x&y)<<1;
		return sum(add,carry);
	}
  }
};
