#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
using namespace std;

int factorial(int num);
vector<int> stat(vector<int> nums);
int main() {
  cout<<"Hellow, world!"<<endl;
  int i=1;
  while(i<11) {
    bool odd=true;
    if(!(i%2)) odd=false;
    cout<<i<<" ";
    if(odd) cout<<"odd"<<endl;
    else {
      cout<<"even"<<endl;
    }
    odd=true;
    i++;
  }
  for(int i=0; i<10; i++) {
    cout<<factorial(i+1)<<endl;
  }
  i=0;
  vector<int> stat_nums;
  while(i<10) {
    int temp;
    cin>>temp;
    stat_nums.push_back(temp);
    i++;
  }
  vector<int> ans;
  ans=stat(stat_nums);
  cout<<"sum: "<<ans[0]<<endl;
  cout<<"min: "<<ans[1]<<endl;
  cout<<"max: "<<ans[2]<<endl;
  cout<<ans[3]<<": "<<ans[4]<<endl;
  vector<int> second;
  ifstream file("nums.txt");
  int file_num;
  /*
  while(getline(file,file_num)) {
    second.push_back(file_num);
  }
  */
  ans=stat(second);
  cout<<"sum: "<<ans[0]<<endl;
  cout<<"min: "<<ans[1]<<endl;
  cout<<"max: "<<ans[2]<<endl;
}

int factorial(int num) {
  if(!num) return 1;
  else return num*factorial(num-1);
}

vector<int> stat(vector<int> nums) {
  vector<int> ans;
  int sum=0;
  int min=nums[0];
  int max=nums[0];
  map<int,int> count;
  for(int i=0; i<nums.size(); i++) {
    sum+=nums[i];
    if(nums[i]<min) min=nums[i];
    if(nums[i]>max) max=nums[i];
    if(count.find(nums[i])==count.end()) {
      count[nums[i]]=1;
    } else {
      count[nums[i]]=count[nums[i]]+1;
    }
  }
  ans.push_back(sum);
  ans.push_back(min);
  ans.push_back(max);
  
  return ans;
}
