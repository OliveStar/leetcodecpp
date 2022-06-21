class Solution {
public:
    /*
        算法：依据“/”分割路径字符串，将分割后的文件夹（或文件）名称（记为字符串curFolder）依次缓存下来，依据curFolder进行分类处理：
        1.如果curFolder为空，表明是连续的"/"，不做处理
        2.如果curFolder不为空，依据如下分类处理之后清空curFolder：
            a. 为"."：代表当前文件夹，不处理；
            b. 为".."：代表回退到上层文件夹，此时删除上一文件夹，需要判断缓存是否为空，如果为空不处理；
            c. 其他情况依次将curFolder加入缓存
        最后再将各级文件夹串接为最终简化后的路径字符串，注意最后没有“/”
    */
    string simplifyPath(string path) {
        vector<string> folders;
        string curFolder = "";
        string ret = "/";

        path += '/';
        for(char ch : path){
            if(ch == '/'){
                if(!curFolder.empty()){
                    if(curFolder == ".."){
                        if(!folders.empty())
                            folders.pop_back();
                    }
                    else if(curFolder != "."){
                        folders.push_back(curFolder);
                    }
                    curFolder = "";
                }
            }
            else
                curFolder += ch;
        }

        for(int i = 0; i + 1 < folders.size(); i++)
            ret += (folders[i] + '/');
        if(!folders.empty())
            ret += folders.back();
        
        return ret;
    }
};