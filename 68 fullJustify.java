class Solution {
    /**
    算法：字符串大模拟，分类讨论
    1.如果当前行只有一个单词，特殊处理为左对齐；
    2.如果当前行为最后一行，特殊处理为左对齐；
    3.其余为一般情况，分别计算「当前行单词总长度」、「当前行空格总长度」和「往下取整后的单位空格长度」  ，
    然后依次进行拼接。当空格无法均分时，每次往靠左的间隙多添加一个空格，直到剩余的空格能够被后面的间隙所均分。
    时间复杂度：会对words 做线性扫描，最坏情况下每个words[i] 独占一行，此时所有字符串的长度为n∗maxWidth。复杂度为O(n∗maxWidth)
    空间复杂度：最坏情况下每个words[i] 独占一行，复杂度为O(n∗maxWidth)
     */
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> ans = new ArrayList<>();
        int n = words.length;
        List<String> list = new ArrayList<>();
        for(int i = 0; i < n;){
            // word[i]是我们当前需要考虑的word
            // list暂时存储当前行能放的单词
            list.clear();
            list.add(words[i]);
            int cur = words[i++].length();
            // 第1步: 我们首先贪心的看能放多少个单词, 贪心的意思是先不考虑左右对齐的情况, 单词间空格数只为1
            // 看看当前这个词能否放入本轮中，条件判断为: 当前剩余的可长度大于当前要放入单词的长度, 要注意如果当前放入的不是第一个单词, 我们还需要加上前置空格占用的长度
            while(i < n && cur + 1 + words[i].length() <= maxWidth){
                cur += 1 + words[i].length();
                list.add(words[i++]);
            }

            // 第2步: 开始考虑生成左右对齐的字符串
            // 由题目中给定条件, 我们可以得出有以几种情况:
            // 情况1: 当前行为最后一行, 左对齐即可, 不用考虑单词间空格长度的问题
            // 情况2: 当前行单词数量为1, 左对齐即可, 不用考虑单词间空格长度的问题
            // 情况3: 普遍情况: 非最后一行且行内单词数不唯一, 我们要考虑左右对齐
            // 进一步抽象, 需要用一下几个变量:
            // 空格位置的数量: (这个就是本行单词数减1, 比如: 2个单词有1个空格位置, 3个单词有2个空格位置)
            // 每个空格位置的基本空格数量: (我们要均分空格到每一个空格位置, 这里就是总的空格数量下整除空格位置的数量)
            // 因为有可能出现不能整除的情况, 所以我们需要有前几个空格位置会相对于后面的空格位置多1个空格

            // 当前行为最后一行，特殊处理为左对齐
            if(i == n){
                StringBuilder sb = new StringBuilder(list.get(0));
                for(int k = 1; k < list.size(); k++){
                    sb.append(" ").append(list.get(k));
                }
                while(sb.length() < maxWidth) sb.append(" ");
                ans.add(sb.toString());
                break;
            }

            // 如果当前行只有一个word, 特殊处理为左对齐
            int cnt = list.size();
            if(cnt == 1){
                String str = list.get(0);
                while(str.length() != maxWidth) str += " ";
                ans.add(str);
                continue;
            }

            /**
             * 其余为一般情况
             * wordWidth: 当前行单词总长度
             * spaceWidth: 当前行空格总长度
             * spaceItem：往下取整后的单位空格长度
             */
            
            int wordWidth = cur - (cnt - 1);
            int spaceWidth = maxWidth - wordWidth;
            int spaceItemWidth = spaceWidth / (cnt - 1);
            String spaceItem = "";
            for(int k = 0; k < spaceItemWidth; k++) spaceItem += " ";
            StringBuilder sb = new StringBuilder();
            for(int k = 0, sum = 0; k < cnt; k++){
                String item = list.get(k);
                sb.append(item);
                if(k == cnt - 1) break;
                sb.append(spaceItem);
                sum += spaceItemWidth;
                // 剩余的间隙数量（可填入空格的次数）
                int remain = cnt - k - 1 - 1;
                // 剩余间隙数量 * 最小单位空格长度 + 当前空格长度 < 单词总长度，则在当前间隙多补充一个空格
                if(remain * spaceItemWidth + sum < spaceWidth){
                    sb.append(" ");
                    sum++;
                }
            }
            ans.add(sb.toString());
        }
        return ans;
    }   
}