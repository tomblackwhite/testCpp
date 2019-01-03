#include "TextQuery.hpp"
TextQuery::TextQuery(std::ifstream &is):file(new std::vector<std::string>)
{
    std::string text;
    while(getline(is,text))
    {
        file->push_back(text);//插入每一行
        int n = file->size() - 1;//行数
        std::istringstream line(text);
        std::string word;
        while(line>>word)
        {
            auto &lines = wm[word];//插入单词 若不存在返回空，并插入键值
            if(!lines)//不存在时smart pointer resets a new set
                lines.reset(new std::set<line_no>);
            lines->insert(n);//然后插入当前行
        }
    }
}
QueryResult TextQuery::query(const std::string&sought) const
{
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    auto loc = wm.find(sought);//查找某个word对应的pair
    if(loc==wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}
std::ostream &print(std::ostream &os,const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "times", "s") << std::endl;
    for(auto num:*qr.lines)
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << std::endl;
    return os;
}
std::string make_plural(size_t ctr,const std::string &word,
                        const std::string &ending)
{
    return (ctr > 1) ? word + ending : word;
}