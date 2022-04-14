// 大数乘法
// 字符串实现，很大的数字，无法直接计算乘积，分解成一位数的乘法运算，避免溢出
// 用两个指针i，j在num1和num2上游走，计算乘积，同时将乘积叠加到res的正确位置
// 列出竖式，可以发现，num1[i]和num2[j]的乘积对应的就是res[i+j]和res[i+j+1]这两个位置

string multiply(string num1, string num2){
    int m = num1.size(), n = num2.size();
    // 结果最多为m+n位数
    vector<int> res(m+n, 0);
    // 从个位数开始逐位相乘
    for(int i = m-1; i >= 0; i--)
        for(int j = n - 1; j >= 0; j--){
            int mul = (num1[i] - '0') * (num2[i] - '0');
            // 乘积在res对应的索引位置
            int p1 = i+j, p2 = i+j+1;
            // 叠加到res上
            int sum = mul + res[p2];
            res[p2] = sum % 10;
            res[p1] += sum/10;
        }
    
    // 结果前缀可能存的0(未使用的位)
    int i = 0;
    while(i < res.size() && res[i] == 0)
        i++;
    //将计算结果转化成字符串
    string str;
    for(;i < res.size(); i++)
        str.push_back('0' + res[i]);
    
    return str.size() == 0 ? "0" : str;
}