#include <cstddef>

namespace ccutil {

template <typename TupleType>
class TupleIterator;

template <typename Ty1, typename... Types>
struct Tuple {
  Ty1 first;
  using Base = Tuple<Types...>;
  Base rest;

  Tuple(Ty1 first, Types... rest) : first(first), rest(rest...) {}
};

template <typename Ty1>
struct Tuple<Ty1> {
  Ty1 first;

  Tuple(Ty1 first) : first(first) {}
};

template <size_t N, typename _Tuple>
constexpr auto& Get(_Tuple& t) {
  if constexpr (N == 0) {
    return t.first;
  } else {
    return Get<N - 1>(t.rest);
  }
}

template <size_t N, typename _Tuple>
constexpr const auto& Get(const _Tuple& t) {
  if constexpr (N == 0) {
    return t.first;
  } else {
    return Get<N - 1>(t.rest);
  }
}

template <typename... Ty1, typename... Ty2>
constexpr bool operator==(const Tuple<Ty1...>& lhs, const Tuple<Ty2...>& rhs) {
  if constexpr (sizeof...(Ty1) != sizeof...(Ty2)) {
    return false;
  } else {
    return lhs.first == rhs.first && lhs.rest == rhs.rest;
  }
}

template <typename Ty1>
constexpr bool operator==(const Tuple<Ty1>& lhs, const Tuple<Ty1>& rhs) {
  return lhs.first == rhs.first;
}

template <typename... Ty1, typename... Ty2>
constexpr bool operator!=(const Tuple<Ty1...>& lhs, const Tuple<Ty2...>& rhs) {
  return !(lhs == rhs);
}

}  // namespace ccutil
