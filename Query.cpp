#include "Query.hpp"
Query::Query(const std::string &str):q(new WordQuery(str))
{ }

QueryResult NotQuery::eval(const TextQuery& tq) const
{
    auto result = query.eval(tq);
    auto first = result.begin(), end = result.end();
    auto line_result = std::make_shared<std::set<line_no>>();
    //line number of  result of set
    auto file = result.getFile(); //file of text
    auto n = file->size();//number of text lines
    for (line_no i = 0; i != n;++i)
    {
        if(first==end||*first!=i)
        {
            line_result->insert(i);//insert the line_number without word
        }
        else if(first!=end)
        {
            ++first;//otherwise get the next number
        }
    }
    return QueryResult(rep(), line_result, file);
}
Query operator~(const Query &q)
{
    return std::shared_ptr<QueryBase>(new NotQuery(q));
}

QueryResult AndQuery::eval(const TextQuery &tq) const
{
    auto lhsresult = lhs.eval(tq), rhsresult = rhs.eval(tq);
    auto line_result = std::make_shared<std::set<line_no>>();
    std::set_intersection(lhsresult.begin(), lhsresult.end(),
                          rhsresult.begin(), rhsresult.end(),
                          std::inserter(*line_result, line_result->begin()));
    return QueryResult(rep(), line_result, lhsresult.getFile());
}

Query operator&(const Query &lhs,const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery &tq) const
{
    auto lhsresult = lhs.eval(tq), rhsresult = rhs.eval(tq);
    auto line_result = 
                std::make_shared<std::set<line_no>>(lhsresult.begin(),lhsresult.end());
    line_result->insert(rhsresult.begin(), rhsresult.end());
    return QueryResult(rep(), line_result, lhsresult.getFile());
}
Query operator|(const Query &lhs,const Query &rhs)
{
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}