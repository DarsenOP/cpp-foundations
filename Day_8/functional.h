//
// Created by arsen on 2/8/25.
//

#ifndef FUNCTIONAL_H
#define FUNCTIONAL_H
#include <functional>
#include <numeric>

template <typename Seq, typename Pred>
Seq filter(Seq s, Pred p)
{
    using f = std::function<bool(typename Seq::value_type)>;

    Seq result;

    std::remove_copy_if(std::begin(s), std::end(s),
        std::back_inserter(result),
        std::not1(f(p)));

    return result;
}

template <typename Seq, typename Pred>
Seq map(Seq s, Pred p)
{
    using val = typename Seq::value_type;
    using f = std::function<val(val)>;

    Seq result;

    std::transform(std::begin(s), std::end(s),
        std::back_inserter(result), f(p));

    return result;
}

template <typename Seq, typename Result, typename Op>
Result reduce(Seq s, Result r, Op op)
{
    return std::accumulate(std::begin(s), std::end(s), r, op);
}

#endif //FUNCTIONAL_H
