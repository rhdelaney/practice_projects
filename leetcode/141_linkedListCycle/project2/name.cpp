#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <queue>
#include <cmath>
using namespace std;

//#include "name.h"
/****************************************************
/ Raychel Delaney
/ CS101
/ Richard Dixon
/
/ This program takes in a name, command and features
/ then proceeds to handle the following operations with 
/ matricies
******************************************************/

class Cell{
	public:
	int x_Value;
	int y_Value;
	int z_Value;
	int q_Value;
	int realValue;
	//vector<Edge> connectedEdges;
	Cell(){
		x_Value = 0; 
		y_Value = 0; 
		z_Value = 0;
		q_Value = 0;
	}
	Cell (int x, int y=0, int z=0, int q=0) {
		x_Value = x; 
		y_Value = y; 
		z_Value = z;
		q_Value = q;
	}
	void setValue(int value){
		realValue=value;
	}
};
class Map{
	public:
	vector <Cell>point;
	int numdims;
	char name;
	int q;
	int x;
	int y;
	int z;
	Map() { x =0; y = 0; z = 0; q=0;}
	void addMap(char title,int dims){
		int num;
		char dummy;
		name=title;
		numdims=dims;
		if(numdims==0){
			cin>>dummy>>num;
			Cell addCell(0,0,0);
			addCell.setValue(num);
			point.push_back(addCell);
			display();
		} else if(numdims==1){
			cin>>x>>dummy;
			y=0;
			z=0;
			build();
			display();
		} else if(numdims==2){
			cin>>x>>dummy>>y>>dummy;
			z=0;
			build();
			display();
		}else{
			cin>>x>>dummy>>y>>dummy>>z>>dummy;
			build();
			display();
		}
	}
	void build(){
		int num;
		char dummy;
		if(numdims==1){
			for(int i=0;i<x;i++){
				cin>>num;
				Cell addCell(i);
				addCell.setValue(num);
				point.push_back(addCell);
				if(i+1<x){
					cin>>dummy;
				}
			}
		}else if(numdims==2){
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					 Cell addCell(i, j);
					 cin>>num;
					 addCell.setValue(num);
                     point.push_back(addCell);
                     if(j+1<y){
             			cin>>dummy;
             		}	
                } if (i+1<x){
             			cin>>dummy;
             	}
			}
		}else{
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					for(int k=0;k<z;k++){
						Cell addCell(i, j, k);
						cin>>num;
						addCell.setValue(num);
                    	point.push_back(addCell);
            	     	if (k+1<z){
             				cin>>dummy;
             			}
            	    } if (j+1<y){
             			cin>>dummy;
             		}            	 
				} if (i+1<x){
             		cin>>dummy;
             	}
			}
		}
	}
	int findSpot (int i, int j){ 	
		return i*y + j; 
	}
	int findSpot(int i, int j, int k){
		return i*y*z + j*z +k; 
	}
	void apply(char title, Map input){
		name=title;
		char oper[500];
		cin>>oper;
		if(strcmp(oper,"+")==0){
			applyAdd(input);
		}
		if(strcmp(oper,"-")==0){
			applySub(input);
		}
		if(strcmp(oper,"*")==0){
			applyMult(input);
		}
		if(strcmp(oper,"%")==0){
			applyRem(input);
		}
		if(strcmp(oper,"max")==0){
			applyMax(input);
		}
		if(strcmp(oper,"min")==0){
			applyMin(input);
		}
		display();
	}
	void applyAdd(Map input){
		if(numdims==0){
			point.at(0).realValue +=input.point.at(0).realValue;
		}else if(numdims==1){
			for(int i=0;i<x;i++){
				point.at(i).realValue+=input.point.at(i).realValue;
			}
		}else if(numdims==2){
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					 point.at(findSpot(i,j)).realValue+=input.point.at(findSpot(i,j)).realValue;
                }
			}
		}else{
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					for(int k=0;k<z;k++){
						point.at(findSpot(i,j,k)).realValue+=input.point.at(findSpot(i,j,k)).realValue;
            	    }     	 
				}
			}
		}
	}
	void applySub(Map input){
		if(numdims==0){
			point.at(0).realValue-=input.point.at(0).realValue;
		}else if(numdims==1){
			for(int i=0;i<x;i++){
				point.at(i).realValue-=input.point.at(i).realValue;
			}
		}else if(numdims==2){
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					 point.at(findSpot(i,j)).realValue-=input.point.at(findSpot(i,j)).realValue;
                }
			}
		}else{
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					for(int k=0;k<z;k++){
						point.at(findSpot(i,j,k)).realValue-=input.point.at(findSpot(i,j,k)).realValue;
            	    }     	 
				}
			}
		}
	}
	void applyMult(Map input){
		if(numdims==0){
			point.at(0).realValue*=input.point.at(0).realValue;
		}else if(numdims==1){
			for(int i=0;i<x;i++){
				point.at(i).realValue*=input.point.at(i).realValue;
			}
		}else if(numdims==2){
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					 point.at(findSpot(i,j)).realValue*=input.point.at(findSpot(i,j)).realValue;
                }
			}
		}else{
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					for(int k=0;k<z;k++){
						point.at(findSpot(i,j,k)).realValue*=input.point.at(findSpot(i,j,k)).realValue;
            	    }     	 
				}
			}
		}
	}
	void applyRem(Map input){
		if(numdims==0){
			point.at(0).realValue%=input.point.at(0).realValue;
		}else if(numdims==1){
			for(int i=0;i<x;i++){
				point.at(i).realValue%=input.point.at(i).realValue;
			}
		}else if(numdims==2){
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					 point.at(findSpot(i,j)).realValue%=input.point.at(findSpot(i,j)).realValue;
                }
			}
		}else{
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					for(int k=0;k<z;k++){
						point.at(findSpot(i,j,k)).realValue%=input.point.at(findSpot(i,j,k)).realValue;
            	    }     	 
				}
			}
		}
	}
	void applyMax(Map input){
		if(numdims==0){
			point.at(0).realValue = input.point.at(0).realValue > point.at(0).realValue? input.point.at(0).realValue : point.at(0).realValue;
		}else if(numdims==1){
			for(int i=0;i<x;i++){
				point.at(i).realValue= input.point.at(i).realValue > point.at(i).realValue? input.point.at(i).realValue : point.at(i).realValue;
			}
		}else if(numdims==2){
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					point.at(findSpot(i,j)).realValue= input.point.at(findSpot(i,j)).realValue > point.at(findSpot(i,j)).realValue? input.point.at(findSpot(i,j)).realValue : point.at(findSpot(i,j)).realValue;
                }
			}
		}else{
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					for(int k=0;k<z;k++){
						point.at(findSpot(i,j,k)).realValue= input.point.at(findSpot(i,j,k)).realValue > point.at(findSpot(i,j,k)).realValue? input.point.at(findSpot(i,j,k)).realValue : point.at(findSpot(i,j,k)).realValue;
            	    }     	 
				}
			}
		}
	}
	void applyMin(Map input){
		if(numdims==0){
			point.at(0).realValue = input.point.at(0).realValue < point.at(0).realValue? input.point.at(0).realValue : point.at(0).realValue;
		} else if(numdims==1){
			for(int i=0;i<x;i++){
				point.at(i).realValue= input.point.at(i).realValue < point.at(i).realValue? input.point.at(i).realValue : point.at(i).realValue;
			}
		}else if(numdims==2){
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					point.at(findSpot(i,j)).realValue= input.point.at(findSpot(i,j)).realValue < point.at(findSpot(i,j)).realValue? input.point.at(findSpot(i,j)).realValue : point.at(findSpot(i,j)).realValue;
                }
			}
		}else{
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					for(int k=0;k<z;k++){
						point.at(findSpot(i,j,k)).realValue= input.point.at(findSpot(i,j,k)).realValue < point.at(findSpot(i,j,k)).realValue? input.point.at(findSpot(i,j,k)).realValue : point.at(findSpot(i,j,k)).realValue;
            	    }     	 
				}
			}
		}
	}
	void cross(char title, Map input1, Map input2){
		name = title;
		numdims = input1.numdims + input2.numdims;
		char oper[500];
		cin>>oper;
		if(strcmp(oper,"+")==0){
			crossAdd(input1,input2);
		}
		if(strcmp(oper,"–")==0){
			crossSub(input1,input2);
		}
		if(strcmp(oper,"*")==0){
			crossMult(input1,input2);
		}
		if(strcmp(oper,"%")==0){
			crossRem(input1,input2);
		}
		if(strcmp(oper,"max")==0){
			crossMax(input1,input2);
		}
		if(strcmp(oper,"min")==0){
			crossMin(input1,input2);
		}
		display();
	}
	void crossAdd(Map input1, Map input2){
		int num=0;
		if(numdims==0){
			Cell addCell(0);
			num=input1.point.at(0).realValue + input2.point.at(0).realValue;
			addCell.setValue(num);
            point.push_back(addCell);
		}else if(numdims==1){
			if(input1.x<input2.x){
				for(int i=0;i<x;i++){
					Cell addCell(i);
					num=input1.point.at(0).realValue + input2.point.at(i).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
                }
                x=input2.x;
			}else{
				for(int i=0;i<x;i++){
					Cell addCell(i);
					num=input1.point.at(i).realValue + input2.point.at(0).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
				}
				x=input1.x;
			}
		}else if(numdims==2){
			x=input1.x;
			y=input2.x;
			for(int i=0;i<input1.x;i++){
				for(int j=0;j<input2.x;j++){
					Cell addCell(i,j);
					num=input1.point.at(i).realValue + input2.point.at(j).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
                }
			}
		}else{
			if(input1.numdims==1 && input2.numdims==2){
				for (int i = 0; i < input1.x; ++i){
					for (int j = 0; j < input2.x * input2.y; ++j){
						Cell addCell(i,j);
						num=input1.point.at(i).realValue + input2.point.at(findSpot(i,j)).realValue;
						addCell.setValue(num);
	                   	point.push_back(addCell);
	                }
	            }
            	x=input1.x;
				y=input2.x;
				z=input2.y;
			} else if(input1.numdims==2 && input2.numdims==1){
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.x;k++){
							Cell addCell(i,j,k);
							num=input1.point.at(i*input1.y+ j).realValue + input2.point.at(k).realValue;
							addCell.setValue(num);
            	        	point.push_back(addCell);
           		 	    }     	 
					}
				}
				x=input1.x;
				y=input1.y;
				z=input2.x;
			}else if(input1.numdims==2 && input2.numdims==2){	
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.x;k++){
							for (int m = 0; m < input2.y; ++m){
								Cell addCell(i,j,k,m);
								num=input1.point.at(i*input1.y+ j).realValue + input2.point.at(k * input2.y + m).realValue;
								addCell.setValue(num);
	            	        	point.push_back(addCell);
	            	        }
           		 	    }     	 
					}
				}
				x=input1.x;
				y=input1.y;
				z=input2.x;
				q=input2.y;
			}else{
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.y;k++){
							Cell addCell(i,j,k);
							num=input1.point.at(findSpot(i,j)).realValue + input2.point.at(k).realValue;
							addCell.setValue(num);
            	        	point.push_back(addCell);
           		 	    }     	 
					}
				}
			}
		}
	}
	void crossSub(Map input1,Map input2){
		int num=0;
		if(numdims==0){
			Cell addCell(0);
			num=input1.point.at(0).realValue - input2.point.at(0).realValue;
			addCell.setValue(num);
            point.push_back(addCell);
		}else if(numdims==1){
			if(input1.x<input2.x){
				for(int i=0;i<x;i++){
					Cell addCell(i);
					num=input1.point.at(0).realValue - input2.point.at(i).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
                }
                x=input2.x;
			}else{
				for(int i=0;i<x;i++){
					Cell addCell(i);
					num=input1.point.at(i).realValue - input2.point.at(0).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
				}
				x=input1.x;
			}
		}else if(numdims==2){
			x=input1.x;
			y=input2.x;
			for(int i=0;i<input1.x;i++){
				for(int j=0;j<input2.x;j++){
					Cell addCell(i,j);
					num=input1.point.at(i).realValue - input2.point.at(j).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
                }
			}
		}else{
			if(input1.numdims==1 && input2.numdims==2){
				for (int i = 0; i < input1.x; ++i){
					for (int j = 0; j < input2.x * input2.y; ++j){
						Cell addCell(i,j);
						num=input1.point.at(i).realValue - input2.point.at(findSpot(i,j)).realValue;
						addCell.setValue(num);
	                   	point.push_back(addCell);
	                }
	            }
            	x=input1.x;
				y=input2.x;
				z=input2.y;
			} else if(input1.numdims==2 && input2.numdims==1){
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.x;k++){
							Cell addCell(i,j,k);
							num=input1.point.at(i*input1.y+ j).realValue - input2.point.at(k).realValue;
							addCell.setValue(num);
            	        	point.push_back(addCell);
           		 	    }     	 
					}
				}
				x=input1.x;
				y=input1.y;
				z=input2.x;
			} else if(input1.numdims==2 && input2.numdims==2){	
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.x;k++){
							for (int m = 0; m < input2.y; ++m){
								Cell addCell(i,j,k,m);
								num=input1.point.at(i*input1.y+ j).realValue - input2.point.at(k * input2.y + m).realValue;
								addCell.setValue(num);
	            	        	point.push_back(addCell);
	            	        }
           		 	    }     	 
					}
				}
				x=input1.x;
				y=input1.y;
				z=input2.x;
				q=input2.y;
			} else{
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.y;k++){
							Cell addCell(i,j,k);
							num=input1.point.at(findSpot(i,j)).realValue - input2.point.at(k).realValue;
							addCell.setValue(num);
            	        	point.push_back(addCell);
           		 	    }     	 
					}
				}
			}
		}
	}
	void crossMult(Map input1,Map input2){
		int num=0;
		if(numdims==0){
			Cell addCell(0);
			num=input1.point.at(0).realValue * input2.point.at(0).realValue;
			addCell.setValue(num);
            point.push_back(addCell);
		}else if(numdims==1){
			if(input1.x<input2.x){
				for(int i=0;i<x;i++){
					Cell addCell(i);
					num=input1.point.at(0).realValue * input2.point.at(i).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
                }
                x=input2.x;
			}else{
				for(int i=0;i<x;i++){
					Cell addCell(i);
					num=input1.point.at(i).realValue * input2.point.at(0).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
				}
				x=input1.x;
			}
		}else if(numdims==2){
			x=input1.x;
			y=input2.x;
			for(int i=0;i<input1.x;i++){
				for(int j=0;j<input2.x;j++){
					Cell addCell(i,j);
					num=input1.point.at(i).realValue*input2.point.at(j).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
                }
			}
		}else{
			if(input1.numdims==1 && input2.numdims==2){
				for (int i = 0; i < input1.x; ++i){
					for (int j = 0; j < input2.x * input2.y; ++j){
						Cell addCell(i,j);
						num=input1.point.at(i).realValue * input2.point.at(findSpot(i,j)).realValue;
						addCell.setValue(num);
	                   	point.push_back(addCell);
	                }
	            }
            	x=input1.x;
				y=input2.x;
				z=input2.y;
			} else if(input1.numdims==2 && input2.numdims==1){
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.x;k++){
							Cell addCell(i,j,k);
							num=input1.point.at(i*input1.y+ j).realValue * input2.point.at(k).realValue;
							addCell.setValue(num);
            	        	point.push_back(addCell);
           		 	    }     	 
					}
				}
				x=input1.x;
				y=input1.y;
				z=input2.x;
			}else if(input1.numdims==2 && input2.numdims==2){	
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.x;k++){
							for (int m = 0; m < input2.y; ++m){
								Cell addCell(i,j,k,m);
								num=input1.point.at(i*input1.y+ j).realValue * input2.point.at(k * input2.y + m).realValue;
								addCell.setValue(num);
	            	        	point.push_back(addCell);
	            	        }
           		 	    }     	 
					}
				}
				x=input1.x;
				y=input1.y;
				z=input2.x;
				q=input2.y;
			}else{
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.y;k++){
							Cell addCell(i,j,k);
							num=input1.point.at(findSpot(i,j)).realValue * input2.point.at(k).realValue;
							addCell.setValue(num);
            	        	point.push_back(addCell);
           		 	    }     	 
					}
				}
			}
		}
	}
	void crossRem(Map input1,Map input2){
		int num=0;
		if(numdims==0){
			Cell addCell(0);
			num=input1.point.at(0).realValue % input2.point.at(0).realValue;
			addCell.setValue(num);
            point.push_back(addCell);
		}else if(numdims==1){
			if(input1.x<input2.x){
				for(int i=0;i<x;i++){
					Cell addCell(i);
					num=input1.point.at(0).realValue % input2.point.at(i).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
                }
                x=input2.x;
			}else{
				for(int i=0;i<x;i++){
					Cell addCell(i);
					num=input1.point.at(i).realValue % input2.point.at(0).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
				}
				x=input1.x;
			}
		}else if(numdims==2){
			x=input1.x;
			y=input2.x;
			for(int i=0;i<input1.x;i++){
				for(int j=0;j<input2.x;j++){
					Cell addCell(i,j);
					num=input1.point.at(i).realValue % input2.point.at(j).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
                }
			}
		}else{
			if(input1.numdims==1 && input2.numdims==2){
				for (int i = 0; i < input1.x; ++i){
					for (int j = 0; j < input2.x * input2.y; ++j){
						Cell addCell(i,j);
						num=input1.point.at(i).realValue % input2.point.at(findSpot(i,j)).realValue;
						addCell.setValue(num);
	                   	point.push_back(addCell);
	                }
	            }
            	x=input1.x;
				y=input2.x;
				z=input2.y;
			} else if(input1.numdims==2 && input2.numdims==1){
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.x;k++){
							Cell addCell(i,j,k);
							num=input1.point.at(i*input1.y+ j).realValue % input2.point.at(k).realValue;
							addCell.setValue(num);
            	        	point.push_back(addCell);
           		 	    }     	 
					}
				}
				x=input1.x;
				y=input1.y;
				z=input2.x;
			}else if(input1.numdims==2 && input2.numdims==2){	
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.x;k++){
							for (int m = 0; m < input2.y; ++m){
								Cell addCell(i,j,k,m);
								num=input1.point.at(i*input1.y+ j).realValue % input2.point.at(k * input2.y + m).realValue;
								addCell.setValue(num);
	            	        	point.push_back(addCell);
	            	        }
           		 	    }     	 
					}
				}
				x=input1.x;
				y=input1.y;
				z=input2.x;
				q=input2.y;
			} else{
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.y;k++){
							Cell addCell(i,j,k);
							num=input1.point.at(findSpot(i,j)).realValue % input2.point.at(k).realValue;
							addCell.setValue(num);
            	        	point.push_back(addCell);
           		 	    }     	 
					}
				}
			}
		}
	}
	void crossMax(Map input1,Map input2){
		int num=0;
		if(numdims==0){
			Cell addCell(0);
			num	= input1.point.at(0).realValue > input2.point.at(0).realValue? input1.point.at(0).realValue : input2.point.at(0).realValue;
			addCell.setValue(num);
            point.push_back(addCell);
		}else if(numdims==1){
			if(input1.x<input2.x){
				for(int i=0;i<x;i++){
					Cell addCell(i);
					num= input1.point.at(0).realValue > input2.point.at(i).realValue? input1.point.at(0).realValue : input2.point.at(i).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
                }
                x=input2.x;
			}else{
				for(int i=0;i<x;i++){
					Cell addCell(i);
					num= input1.point.at(i).realValue > input2.point.at(0).realValue? input1.point.at(i).realValue : input2.point.at(0).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
				}
				x=input1.x;
			}
		}else if(numdims==2){
			x=input1.x;
			y=input2.x;
			for(int i=0;i<input1.x;i++){
				for(int j=0;j<input2.x;j++){
					Cell addCell(i,j);
					num= input1.point.at(i).realValue > input2.point.at(j).realValue? input1.point.at(i).realValue : input2.point.at(j).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
                }
			}
		}else{
			if(input1.numdims==1 && input2.numdims==2){
				for (int i = 0; i < input1.x; ++i){
					for (int j = 0; j < input2.x * input2.y; ++j){
						Cell addCell(i,j);
						num= input1.point.at(i).realValue > input2.point.at(findSpot(i,j)).realValue? input1.point.at(i).realValue : input2.point.at(findSpot(i,j)).realValue;
						addCell.setValue(num);
	                   	point.push_back(addCell);
	                }
	            }
            	x=input1.x;
				y=input2.x;
				z=input2.y;
			} else if(input1.numdims==2 && input2.numdims==1){
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.x;k++){
							Cell addCell(i,j,k);
							num= input1.point.at(i*input1.y+ j).realValue > input2.point.at(k).realValue? input1.point.at(i*input1.y+ j).realValue : input2.point.at(k).realValue;
							addCell.setValue(num);
            	        	point.push_back(addCell);
           		 	    }     	 
					}
				}
				x=input1.x;
				y=input1.y;
				z=input2.x;
			}else if(input1.numdims==2 && input2.numdims==2){	
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.x;k++){
							for (int m = 0; m < input2.y; ++m){
								Cell addCell(i,j,k,m);
								num= input1.point.at(i*input1.y+ j).realValue > input2.point.at(k * input2.y + m).realValue? input1.point.at(i*input1.y+ j).realValue : input2.point.at(k * input2.y + m).realValue;
								addCell.setValue(num);
	            	        	point.push_back(addCell);
	            	        }
           		 	    }     	 
					}
				}
				x=input1.x;
				y=input1.y;
				z=input2.x;
				q=input2.y;
			}else{
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.y;k++){
							Cell addCell(i,j,k);
							num= input1.point.at(findSpot(i,j)).realValue > input2.point.at(k).realValue? input1.point.at(findSpot(i,j)).realValue : input2.point.at(k).realValue;
							addCell.setValue(num);
            	        	point.push_back(addCell);
           		 	    }     	 
					}
				}
			}
		}
	}
	void crossMin(Map input1, Map input2){
		int num=0;
		if(numdims==0){
			Cell addCell(0);
			num	= input1.point.at(0).realValue < input2.point.at(0).realValue? input1.point.at(0).realValue : input2.point.at(0).realValue;
			addCell.setValue(num);
            point.push_back(addCell);
		}else if(numdims==1){
			if(input1.x<input2.x){
				for(int i=0;i<x;i++){
					Cell addCell(i);
					num= input1.point.at(0).realValue < input2.point.at(i).realValue? input1.point.at(0).realValue : input2.point.at(i).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
                }
                x=input2.x;
			}else{
				for(int i=0;i<x;i++){
					Cell addCell(i);
					num= input1.point.at(i).realValue < input2.point.at(0).realValue? input1.point.at(i).realValue : input2.point.at(0).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
				}
				x=input1.x;
			}
		}else if(numdims==2){
			x=input1.x;
			y=input2.x;
			for(int i=0;i<input1.x;i++){
				for(int j=0;j<input2.x;j++){
					Cell addCell(i,j);
					num= input1.point.at(i).realValue < input2.point.at(j).realValue? input1.point.at(i).realValue : input2.point.at(j).realValue;
					addCell.setValue(num);
                    point.push_back(addCell);
                }
			}
		}else{
			if(input1.numdims==1 && input2.numdims==2){
				for (int i = 0; i < input1.x; ++i){
					for (int j = 0; j < input2.x * input2.y; ++j){
						Cell addCell(i,j);
						num= input1.point.at(i).realValue < input2.point.at(findSpot(i,j)).realValue? input1.point.at(i).realValue : input2.point.at(findSpot(i,j)).realValue;
						addCell.setValue(num);
	                   	point.push_back(addCell);
	                }
	            }
            	x=input1.x;
				y=input2.x;
				z=input2.y;
			} else if(input1.numdims==2 && input2.numdims==1){
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.x;k++){
							Cell addCell(i,j,k);
							num= input1.point.at(i*input1.y+ j).realValue < input2.point.at(k).realValue? input1.point.at(i*input1.y+ j).realValue : input2.point.at(k).realValue;
							addCell.setValue(num);
            	        	point.push_back(addCell);
           		 	    }     	 
					}
				}
				x=input1.x;
				y=input1.y;
				z=input2.x;
			}else if(input1.numdims==2 && input2.numdims==2){	
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.x;k++){
							for (int m = 0; m < input2.y; ++m){
								Cell addCell(i,j,k,m);
								num= input1.point.at(i*input1.y+ j).realValue < input2.point.at(k * input2.y + m).realValue? input1.point.at(i*input1.y+ j).realValue : input2.point.at(k * input2.y + m).realValue;
								addCell.setValue(num);
	            	        	point.push_back(addCell);
	            	        }
           		 	    }     	 
					}
				}
				x=input1.x;
				y=input1.y;
				z=input2.x;
				q=input2.y;
			} else{
				for(int i=0;i<input1.x;i++){
					for(int j=0;j<input1.y;j++){
						for(int k=0;k<input2.y;k++){
							Cell addCell(i,j,k);
							num= input1.point.at(findSpot(i,j)).realValue < input2.point.at(k).realValue? input1.point.at(findSpot(i,j)).realValue : input2.point.at(k).realValue;
							addCell.setValue(num);
            	        	point.push_back(addCell);
           		 	    }     	 
					}
				}
			}
		}	
	}
	void join(char title, Map input1, Map input2){
		name=title;
		//edit this numdims
		numdims=(input1.numdims+input2.numdims)-1;
		char oper[500];
		cin>>oper;
		if(strcmp(oper,"+")==0){
			joinAdd(input1,input2);
		}
		if(strcmp(oper,"-")==0){
			joinSub(input1,input2);
		}
		if(strcmp(oper,"*")==0){
			joinMult(input1,input2);
		}
		if(strcmp(oper,"%")==0){
			joinRem(input1,input2);
		}
		if(strcmp(oper,"max")==0){
			joinMax(input1,input2);
		}
		if(strcmp(oper,"min")==0){
			joinMin(input1,input2);
		}
		display();
	}
	void joinAdd(Map input1,Map input2){
		int num=0;
		if(numdims==1){
			x=input1.x;
			for(int i=0;i<x;i++){
				Cell addCell(i);
				num=input1.point.at(i).realValue + input2.point.at(i).realValue;
				addCell.setValue(num);
        	    point.push_back(addCell);
			}
		}else if(numdims==2){
			x=input1.x;
			y=input1.y;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					Cell addCell(i,j);
					num=input1.point.at(findSpot(i,j)).realValue + input2.point.at(findSpot(i,j)).realValue;
					addCell.setValue(num);
           			point.push_back(addCell);
                }
			}
		}else{							
			x=input1.x;
			y=input1.y;
			z=input2.y;
			for(int i=0;i<x;i++){   
				for(int j=0;j<y;j++){ 
					for(int k=0;k<z;k++){	
						Cell addCell(i,j,k);
						num= input1.point.at(findSpot(i,j)).realValue + input2.point.at(k+j*z).realValue;
						addCell.setValue(num);
           				point.push_back(addCell);
           			}     	 
				}
			}
		}
	}
	void joinSub(Map input1,Map input2){
		int num=0;
		if(numdims==1){
			x=input1.x;
			for(int i=0;i<x;i++){
				Cell addCell(i);
				num=input1.point.at(i).realValue - input2.point.at(i).realValue;
				addCell.setValue(num);
        	    point.push_back(addCell);
			}
		}else if(numdims==2){
			x=input1.x;
			y=input1.y;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					Cell addCell(i,j);
					num=input1.point.at(findSpot(i,j)).realValue - input2.point.at(findSpot(i,j)).realValue;
					addCell.setValue(num);
           			point.push_back(addCell);
                }
			}
		}else{
			x=input1.x;
			y=input1.y;
			z=input2.y;
			for(int i=0;i<x;i++){   
				for(int j=0;j<y;j++){ 
					for(int k=0;k<z;k++){	
						Cell addCell(i,j,k);
						num= input1.point.at(findSpot(i,j)).realValue - input2.point.at(k+j*z).realValue;
						addCell.setValue(num);
           				point.push_back(addCell);
           			}     	 
				}
			}
		}		
	}
	void joinMult(Map input1,Map input2){
		int num=0;
		if(numdims==1){
			x=input1.x;
			for(int i=0;i<x;i++){
				Cell addCell(i);
				num= input1.point.at(i).realValue * input2.point.at(i).realValue;
				addCell.setValue(num);
        	    point.push_back(addCell);
			}
		}else if(numdims==2){
			x=input1.x;
			y=input1.y;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					Cell addCell(i,j);
					num=input1.point.at(findSpot(i,j)).realValue * input2.point.at(findSpot(i,j)).realValue;
					addCell.setValue(num);
           			point.push_back(addCell);
                }
			}
		}else{							
			x=input1.x;
			y=input1.y;
			z=input2.y;
			for(int i=0;i<x;i++){   
				for(int j=0;j<y;j++){ 
					for(int k=0;k<z;k++){	
						Cell addCell(i,j,k);
						num= input1.point.at(findSpot(i,j)).realValue * input2.point.at(k+j*z).realValue;
						addCell.setValue(num);
           				point.push_back(addCell);
           			}     	 
				}
			}
		}
	}
	void joinRem(Map input1,Map input2){
		int num=0;
		if(numdims==1){
			x=input1.x;
			for(int i=0;i<x;i++){
				Cell addCell(i);
				num=input1.point.at(i).realValue % input2.point.at(i).realValue;
				addCell.setValue(num);
        	    point.push_back(addCell);
			}
		}else if(numdims==2){
			x=input1.x;
			y=input1.y;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					Cell addCell(i,j);
					num=input1.point.at(findSpot(i,j)).realValue % input2.point.at(findSpot(i,j)).realValue;
					addCell.setValue(num);
           			point.push_back(addCell);
                }
			}
		}else{					
			x=input1.x;
			y=input1.y;
			z=input2.y;
			for(int i=0;i<x;i++){   
				for(int j=0;j<y;j++){ 
					for(int k=0;k<z;k++){	
						Cell addCell(i,j,k); 
						num= input1.point.at(findSpot(i,j)).realValue % input2.point.at(k+j*z).realValue;
						addCell.setValue(num);
           				point.push_back(addCell);
           			}     	 
				}
			}
		}	
	}
	void joinMax(Map input1,Map input2){
		int num=0;
		if(numdims==1){
			x=input1.x;
			for(int i=0;i<x;i++){
				Cell addCell(i);
				num	= input1.point.at(i).realValue > input2.point.at(i).realValue? input1.point.at(i).realValue : input2.point.at(i).realValue;
				addCell.setValue(num);
        	    point.push_back(addCell);
			}
		}else if(numdims==2){
			x=input1.x;
			y=input1.y;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					Cell addCell(i,j);
					num	= input1.point.at(findSpot(i,j)).realValue > input2.point.at(findSpot(i,j)).realValue? input1.point.at(findSpot(i,j)).realValue : input2.point.at(findSpot(i,j)).realValue;
					addCell.setValue(num);
           			point.push_back(addCell);
                }
			}
		}else if(input1.numdims==2 && input2.numdims==2){


		}else{
			x=input1.x;
			y=input1.y;
			z=input2.y;
			for(int i=0;i<x;i++){   
				for(int j=0;j<y;j++){ 
					for(int k=0;k<z;k++){	
						Cell addCell(i,j,k);
						num	= input1.point.at(findSpot(i,j)).realValue > input2.point.at(k+j*z).realValue? input1.point.at(findSpot(i,j)).realValue : input2.point.at(k+j*z).realValue;
						addCell.setValue(num);
           				point.push_back(addCell);
           			}     	 
				}
			}
		}
	}		
	void joinMin(Map input1,Map input2){
		int num=0;
		if(numdims==1){
			x=input1.x;
			for(int i=0;i<x;i++){
				Cell addCell(i);
				num	= input1.point.at(i).realValue < input2.point.at(i).realValue? input1.point.at(i).realValue : input2.point.at(i).realValue;
				addCell.setValue(num);
        	    point.push_back(addCell);
			}
		}else if(numdims==2){
			x=input1.x;
			y=input1.y;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					Cell addCell(i,j);
					num	= input1.point.at(findSpot(i,j)).realValue < input2.point.at(findSpot(i,j)).realValue? input1.point.at(findSpot(i,j)).realValue : input2.point.at(findSpot(i,j)).realValue;
					addCell.setValue(num);
           			point.push_back(addCell);
                }
			}
		}else{							
			x=input1.x;
			y=input1.y;
			z=input2.y;
			for(int i=0;i<x;i++){    
				for(int j=0;j<y;j++){ 
					for(int k=0;k<z;k++){	
						Cell addCell(i,j,k);
						num	= input1.point.at(findSpot(i,j)).realValue < input2.point.at(k+j*z).realValue? input1.point.at(findSpot(i,j)).realValue : input2.point.at(k+j*z).realValue;
						addCell.setValue(num);
           				point.push_back(addCell);
           			}     	 
				}
			}
		}	
	}
	void reduce(char title, Map input){
		name=title;
		char oper[500];
		int spNum=0;
		cin>>oper>>spNum;
		if(strcmp(oper,"+")==0){
			reduceAdd(input,spNum);
		}
		if(strcmp(oper,"*")==0){
			reduceMult(input,spNum);
		}
		if(strcmp(oper,"max")==0){
			reduceMax(input,spNum);
		}
		if(strcmp(oper,"min")==0){
			reduceMin(input,spNum);
		}
		display();
	}
	void reduceAdd(Map input,int spNum){
		numdims=input.numdims;
		numdims--;
		int num=0;
		if(numdims==0){
			x=input.x;
			for(int i=0;i<x;i++){
				num+=input.point.at(i).realValue;
			}
			Cell addCell(0);
			addCell.setValue(num);
            point.push_back(addCell);
		}else if(numdims==1){
			x=input.x;
			y=input.y;
			for(int i=0;i<input.x;i++){
				for(int j=0;j<input.y;j++){
					 num+=input.point.at(findSpot(i,j)).realValue;
                }
                Cell addCell(i);
				addCell.setValue(num);
           		point.push_back(addCell);
           		num=0;
			}
		}else{
			if(spNum==0){
				x=input.y;
				y=input.z;
				z=input.x;
				int num1=0;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){			
					for (int k= 0; k < z; ++k){ 
						num1+=input.point.at(k * x * y + i * y  + j).realValue;
					}
					Cell aCell(i,j);
					aCell.setValue(num1);
           			point.push_back(aCell);
           			num1=0;		
					}
				}
				z=0;
			}else if(spNum==1){	
				x=input.x;
				y=input.z;
				z= input.y;
				int num1=0;
				for(int i=0;i<x;i++){
					for(int k=0;k<y;k++){
						for (int j= 0; j < z; ++j){
							num1+=input.point.at(i * y * z + j * y + k).realValue;
						}
					Cell aCell(i,k);
					aCell.setValue(num1);
           			point.push_back(aCell);
           			num1=0;
           			}			
				}
				z=0;
			}else{
				x= input.x;
				y= input.y;
				z= input.z;
			int num1=0;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					for (int k= 0; k < z; ++k){
						num1+=input.point.at(findSpot(i,j,k)).realValue;
					}
					Cell aCell(i,j);
					aCell.setValue(num1);
           			point.push_back(aCell);
           			num1=0;		
					}
				}
				z=0;
			}
		}
	}
	void reduceMult(Map input,int spNum){
		numdims=input.numdims;
		numdims--;
		int num=1;
		if(numdims==0){
			for(int i=0;i<input.x;i++){
				num*=input.point.at(i).realValue;
			}
			Cell addCell(0);
			addCell.setValue(num);
            point.push_back(addCell);
		}else if(numdims==1){
			for(int i=0;i<input.x;i++){
				for(int j=0;j<input.y;j++){
					 num*=input.point.at(findSpot(i,j)).realValue;
                }
                Cell addCell(i);
				addCell.setValue(num);
           		point.push_back(addCell);
           		num=1;
			}
		}else{
			if(spNum==0){
				x=input.y;
				y=input.z;
				z=input.x;
				int num1=1;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){			
					for (int k= 0; k < z; ++k){ 
						num1*=input.point.at(k * x * y + i * y  + j).realValue;
					}
					Cell aCell(i,j);
					aCell.setValue(num1);
           			point.push_back(aCell);
           			num1=0+1;		
					}
				}
				z=0;
			}else if(spNum==1){	
				x=input.x;
				y=input.z;
				z= input.y;
				int num1=1;
				for(int i=0;i<x;i++){
					for(int k=0;k<y;k++){
						for (int j= 0; j < z; ++j){
							num1*=input.point.at(i * y * z + j * y + k).realValue;
						}
					Cell aCell(i,k);
					aCell.setValue(num1);
           			point.push_back(aCell);
           			num1=1;
           			}			
				}
				z=0;
			}else{
				x= input.x;
				y= input.y;
				z= input.z;
				int num1=1;
				for(int i=0;i<x;i++){
					for(int j=0;j<y;j++){
						for (int k= 0; k < z; ++k){
							num1*=input.point.at(findSpot(i,j,k)).realValue;
						}
					Cell aCell(i,j);
					aCell.setValue(num1);
	           		point.push_back(aCell);
	          		num1=0+1;		
					}
				}
			z=0;
			}
		}	
	}
	void reduceMax(Map input, int spNum){
		numdims=input.numdims;
		numdims--;
		int num=input.point.at(0).realValue;
		if(numdims==0){
			x=input.x;
			for(int i=0;i<x;i++){
				num = input.point.at(i).realValue > num ? input.point.at(i).realValue : num;
			}
			Cell addCell(0);
			addCell.setValue(num);
            point.push_back(addCell);
		}else if(numdims==1){
			for(int i=0;i<input.x;i++){
				for(int j=0;j<input.y;j++){
					 num = input.point.at(findSpot(i,j)).realValue > num ? input.point.at(findSpot(i,j)).realValue : num;
                }
                Cell addCell(i);
				addCell.setValue(num);
           		point.push_back(addCell);
           		num=input.point.at( 0 ).realValue;
			}
		} else{
			if(spNum==0){
				x=input.y;
				y=input.z;
				z=input.x;
				int num1=input.point.at(0).realValue;
				for(int i=0;i<x;i++){
					for(int j=0;j<y;j++){			
						for (int k= 0; k < z; ++k){ 
							num1 =input.point.at(k * x * y + i * y  + j).realValue > num1 ? input.point.at(k * x * y + i * y  + j).realValue : num1;
						}
						Cell aCell(i,j);
						aCell.setValue(num1);
           				point.push_back(aCell);
           				num1=input.point.at( 0 ).realValue;		
					}
				}
				z=0;
			}else if(spNum==1){	
				x=input.x;
				y=input.z;
				z= input.y;

				int num1=input.point.at(0).realValue;
				for(int i=0;i<x;i++){
					for(int k=0;k<y;k++){
						for (int j= 0; j < z; ++j){
							num1 =input.point.at(i * y * z + j * y + k).realValue > num1 ? input.point.at(i * y * z + j * y + k).realValue : num1;
						}
						Cell aCell(i,k);
						aCell.setValue(num1);
           				point.push_back(aCell);
           				num1=input.point.at( 0 ).realValue;	
           			}			
				}
				z=0;
			}else{
				x= input.x;
				y= input.y;
				z= input.z;
			int num1=input.point.at(0).realValue;	
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					for (int k= 0; k < z; ++k){
						num1 =input.point.at(findSpot(i,j,k)).realValue > num1 ? input.point.at(findSpot(i,j,k)).realValue : num1;
					}
					Cell aCell(i,j);
					aCell.setValue(num1);
           			point.push_back(aCell);
           			num1=num1=input.point.at( 0 ).realValue;			
					}
				}
				z=0;
			}
		}
	}
	void reduceMin(Map input, int spNum){
		numdims=input.numdims;
		numdims--;
		int num=input.point.at(0).realValue;
		if(numdims==0){
			x=input.x;
			for(int i=0;i<x;i++){
				num = input.point.at(i).realValue < num ? input.point.at(i).realValue : num;
			}
			Cell addCell(0);
			addCell.setValue(num);
            point.push_back(addCell);
		}else if(numdims==1){
			for(int i=0;i<input.x;i++){
				for(int j=0;j<input.y;j++){
					 num = input.point.at(findSpot(i,j)).realValue < num ? input.point.at(findSpot(i,j)).realValue : num;
                }
                Cell addCell(i);
				addCell.setValue(num);
           		point.push_back(addCell);
           		num=input.point.at( 0 ).realValue;	
			}
		}else{
			if(spNum==0){
				x=input.y;
				y=input.z;
				z=input.x;
				int num1=input.point.at( 0 ).realValue;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){			
					for (int k= 0; k < z; ++k){ 
						num1 =input.point.at(k * x * y + i * y  + j).realValue < num1 ? input.point.at(k * x * y + i * y  + j).realValue : num1;
					}
					Cell aCell(i,j);
					aCell.setValue(num1);
           			point.push_back(aCell);
           			num1=input.point.at( 0  ).realValue;			
					}
				}
				z=0;
			}else if(spNum==1){	
				x=input.x;
				y=input.z;
				z= input.y;

				int num1=input.point.at( 0).realValue;	
				for(int i=0;i<x;i++){
					for(int k=0;k<y;k++){
						for (int j= 0; j < z; ++j){
							num1 =input.point.at(i * y * z + j * y + k).realValue < num1 ? input.point.at(i * y * z + j * y + k).realValue : num1;
						}
					Cell aCell(i,k);
					aCell.setValue(num1);
           			point.push_back(aCell);
           			num1=input.point.at( 0  ).realValue;
           			}			
				}
				z=0;
			}else{
				x= input.x;
				y= input.y;
				z= input.z;
			int num1=input.point.at( 0 ).realValue;	
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					for (int k= 0; k < z; ++k){
						num1 =input.point.at(findSpot(i,j,k)).realValue < num1 ? input.point.at(findSpot(i,j,k)).realValue : num1;
					}
					Cell aCell(i,j);
					aCell.setValue(num1);
           			point.push_back(aCell);
           			num1=input.point.at( 0  ).realValue;	
					}
				}
				z=0;
			}
		}
	}
	void cat(char title, Map input1, Map input2){
		name=title;
		numdims=input1.numdims;
		int spNum;
		cin>>spNum;
		if(spNum==0){
			catZero(input1,input2);
		}
		if(spNum==1){
			catOne(input1, input2);
		}	
		display();
	}
	void catZero(Map input1, Map input2){
		int num=0;
		if(numdims==0){
			num=input1.point.at(0).realValue;
			Cell addCell(0);
			addCell.setValue(num);
            point.push_back(addCell);
            num=input2.point.at(0).realValue;
			Cell diffCell(1);
			addCell.setValue(num);
            point.push_back(diffCell);
		}else if(numdims==1){
			x=input1.x + input2.x;
			int j=0;
			for(int i=0;i<x;i++){
				if(i<input1.x){
					num=input1.point.at(i).realValue;
				}else{
					num=input2.point.at(j).realValue;
					j++;
				}
                Cell addCell(i);
				addCell.setValue(num);
           		point.push_back(addCell);
			}
		} else if(numdims==2){
			x= input1.x + input2.x;
			y= input1.y;
			for(int i=0;i<input1.x;i++){
				for(int j=0;j<input1.y;j++){
					num=input1.point.at(findSpot(i,j)).realValue;
            	    Cell addCell(i,j);
					addCell.setValue(num);
        			point.push_back(addCell);
        		}
          	}
          	for (int i = 0; i < input2.x; ++i){
          		for (int j = 0; j < input2.y; ++j){
          			num = input2.point.at(findSpot(i, j)).realValue;
          			Cell addCell(input1.x+i,j);
					addCell.setValue(num);
        			point.push_back(addCell);
        		} 
			}

		} else{
			x=input1.x + input2.x;
			y=input1.y + input2.y;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					if(i<input1.x){
						num=input1.point.at(findSpot(i,j)).realValue;
					} else{
						num=input2.point.at(findSpot(i,j)).realValue;
					}
            		Cell addCell(i,j);
					addCell.setValue(num);
           			point.push_back(addCell);
           		}  	 
			}
		}	
	}
	void catOne(Map input1, Map input2){
		int num=0;
		if(numdims==0){
			//cout<<"Are you in numdims=0?"<<endl;
			num=input1.point.at(0).realValue;
			Cell addCell(0);
			addCell.setValue(num);
            point.push_back(addCell);
            num=input2.point.at(0).realValue;
			Cell diffCell(1);
			addCell.setValue(num);
            point.push_back(diffCell);
		}else if(numdims==1){
			//cout<<"Are you in numdims=1?"<<endl;
			x=input1.x + input2.x;
			int j=0;
			for(int i=0;i<x;i++){
				if(i<input1.x){
					num=input1.point.at(i).realValue;
				}else{
					num=input2.point.at(j).realValue;
					j++;
				}
                Cell addCell(i);
				addCell.setValue(num);
           		point.push_back(addCell);
			}
		} else if(numdims==2){
			//cout<<"Are you in numdims=2?"<<endl;
			x= input1.x; //2 to --> 5
			y= input1.y + input2.y;
			for(int i=0;i<input1.x;i++){
				for(int j=0;j<input1.y;j++){
					//cout<<"in the first loop "<<input1.point.at(i*input1.y + j).realValue<<", ";
					num = input1.point.at(i*input1.y + j).realValue;
            	  	Cell addCell(i,j);
					addCell.setValue(num);
        			point.push_back(addCell);
        		}
        		for (int j = 0; j < input2.y; ++j){
          			//cout<<"in the second loop "<<input2.point.at(i*input2.y + j).realValue<<", ";
          			num = input2.point.at(i*input2.y + j).realValue;
          			Cell diffCell(i,input1.y + j);
					diffCell.setValue(num);
        			point.push_back(diffCell);
        		} 
          	}
		} else{
			//cout<<"Are you in numdims++?"<<endl;
			x=input1.x + input2.x;
			y=input1.y + input2.y;
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					if(i<input1.x){
						num=input1.point.at(findSpot(i,j)).realValue;
					} else{
						num=input2.point.at(findSpot(i,j)).realValue;
					}
            		Cell addCell(i,j);
					addCell.setValue(num);
           			point.push_back(addCell);
           		}  	 
			}
		}	
	}
	void copy(Map input){
		numdims=input.numdims;
		x=input.x;
		y=input.y;
		z=input.z;
		int num;
		if(numdims==1){
			for(int i=0;i<x;i++){
				Cell addCell(i);
				num=input.point.at(i).realValue;
				addCell.setValue(num);
				point.push_back(addCell);
			}
		}else if(numdims==2){
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					 Cell addCell(i, j);
					 num=input.point.at(findSpot(i,j)).realValue;
					 addCell.setValue(num);
                     point.push_back(addCell);
                }
			}
		}else{
			for(int i=0;i<x;i++){
				for(int j=0;j<y;j++){
					for(int k=0;k<z;k++){
						Cell addCell(i, j, k);
						num=input.point.at(findSpot(i,j,k)).realValue;
						addCell.setValue(num);
                    	point.push_back(addCell);
            	    }     	 
				}
			}
		}
	}
	void display(){
		//cout<<"in display"<<endl;
		int spot=0;
		if(numdims==0){
			cout<<name<<" = "<<point.at(0).realValue<<endl;
		} else if(numdims==1){
			cout<<name<<" = [";
			for(int i=0;i<x;i++){
				cout<<point.at(i).realValue;
				if(i+1<x){
					cout<<",";
				}
			}
			cout<<"]"<<endl;
		} else if(numdims==2){
			cout<<name<<" = [";
			for (int i = 0; i < x; ++i){
				cout<<"[";
				for(int j=0; j< y; j++){
					spot=findSpot(i,j);
					cout<<point.at(spot).realValue;
					if(j+1<y){
						cout<<",";
					}
				}
				cout<<"]";
				if (i+1<x){
					cout<<",";
				}	
			}
			cout<<"]"<<endl;
		} else if (numdims==3){
			cout<<name<<" = [";
			for (int i = 0; i < x; ++i){
				cout<<"[";
				for(int j=0; j< y; j++){
					cout<<"[";
					for (int k = 0; k < z; ++k){
						spot=findSpot(i,j,k);
						cout<<point.at(spot).realValue;
						if(k+1<z){
							cout<<",";
						}
					}
					cout<<"]";
					if(j+1<y){
						cout<<",";
					}
				}
				cout<<"]";
				if (i+1<x){
					cout<<",";
				}	
			}
			cout<<"]"<<endl;
		} else{
			cout<<name<<" = [";
			for (int i = 0; i < x; ++i){
				cout<<"[";
				for(int j=0; j< y; j++){
					cout<<"[";
					for (int k = 0; k < z; ++k){
						cout<<"[";
						for (int m = 0; m < q; ++m){
							spot=(i*y*z*q + j*z*q + k*q +m);
							cout<<point.at(spot).realValue;
							if(m+1<q){
								cout<<",";
							}
						}
						cout<<"]";
						if(k+1<z){
							cout<<",";
						}
					}
					cout<<"]";
					if(j+1<y){
						cout<<",";
					}
				}
				cout<<"]";
				if (i+1<x){
					cout<<",";
				}	
			}
			cout<<"]"<<endl;
		}
	}	
};
int main(){
	vector<Map> p2;
	char name;
	char dummy;
	char command[500]; 
	int numdims=0;
//note first num in dimlist is the dimensions
while(cin>>name){
		Map dis;
		//cout<<"In the while loop\n";
		cin>>command;
		if(strcmp(command,"build")==0){
			//cout<<"in build\n";
			cin>>numdims>>dummy;
			dis.addMap(name,numdims);
		}
		if(strcmp(command,"apply")==0){
			//cout<<"In apply\n";
			char name1;
			char name2;
			cin>>name1>>name2;
			for(unsigned int i=0;i<p2.size();i++){
				if(p2.at(i).name==name1){
						dis.copy(p2.at(i));
				}
			}
			for(unsigned int i=0;i<p2.size();i++){
				if(p2.at(i).name==name2){
						dis.apply(name, p2.at(i));
				}
			}
		}
		if(strcmp(command,"cross")==0){
			//cout<<"in cross\n";
			char name1;
			char name2;
			cin>>name1>>name2;
			int spot1=0, spot2=0;
			for(unsigned int i=0;i<p2.size();i++){
				if(p2.at(i).name==name1){
					spot1=i;
				}
			}
			for(unsigned int j=0;j<p2.size();j++){
				if(p2.at(j).name==name2){
					spot2=j;
				}
			}
			dis.cross(name,p2.at(spot1),p2.at(spot2));
		}
		if(strcmp(command,"join")==0){
			//cout<<"in join\n";
			char name1;
			char name2;
			cin>>name1>>name2;
			int spot1=0, spot2=0;
			for(unsigned int i=0;i<p2.size();i++){
				if(p2.at(i).name==name1){
					spot1=i;
				}
			}
			for(unsigned int j=0;j<p2.size();j++){
				if(p2.at(j).name==name2){
					spot2=j;
				}
			}
			dis.join(name,p2.at(spot1),p2.at(spot2));
		}
		if(strcmp(command,"reduce")==0){
			//cout<<"in reduce\n";
			char name1;
			cin>>name1;
			int spot1=0;
			for(unsigned int i=0;i<p2.size();i++){
				if(p2.at(i).name==name1){
					spot1=i;
				}
			}
			dis.reduce(name,p2.at(spot1));
		}
		if(strcmp(command,"catenate")==0){
			//cout<<"in catenate"<<endl;
			char name1;
			char name2;
			cin>>name1>>name2;
			int spot1=0, spot2=0;
			for(unsigned int i=0;i<p2.size();i++){
				if(p2.at(i).name==name1){
					spot1=i;
				}
			}
			for(unsigned int j=0;j<p2.size();j++){
				if(p2.at(j).name==name2){
					spot2=j;
				}
			}
			dis.cat(name,p2.at(spot1),p2.at(spot2));
		}
		p2.push_back(dis);
	}
	return 0;
}