
// 请关闭中文输入法，用英文的字母和标点符号。
// 如果你想运行系统测试用例，请点击【执行代码】按钮，如果你想提交作答结果，请点击【提交】按钮，
// 注意：除答案外，请不要打印其他任何多余的字符，以免影响结果验证
// 本OJ系统是基于 OxCoder 技术开发，网址：www.oxcoder.com
// 模版代码提供基本的输入输出框架，可按个人代码习惯修改



#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int solution(int n, std::vector<int>& vec){
    int result=-1000;
    // TODO:
    std::vector<int> presum(n+1);
    presum[0]=0;
    for(int i=1;i<=n;i++){
        presum[i]=presum[i-1]+vec[i-1];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            int tmp = presum[j]-presum[i];
            result=result>tmp?result:tmp;
        }
    }
    return result;
}

int main() {

    int n;

    std::cin>>n;
    std::vector<int> vec(n);

    for(int i=0;i<n;i++){
        std::cin>>vec[i];
    }

    std::cout<<"hahah"<<std::endl;
    for(int i=0;i<n;i++){
        std::cout<<vec[i];
    }
    int result = solution(n,vec);

    std::cout<<result<<std::endl;

    return 0;
}