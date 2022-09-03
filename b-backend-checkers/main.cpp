#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

typedef std::pair<uint16_t, uint16_t> Point;
struct PairHash {
  inline std::size_t operator()(const Point& v) const {
    return v.first * 31 + v.second;
  }
};
typedef std::unordered_set<Point, PairHash> PointsSet;

bool a_point_may_beat(const uint16_t n, const uint16_t m, const Point& a_point,
                      const PointsSet& a_points_set, const PointsSet& z_points_set) {
  // left up
  if (a_point.first-2 >= 0 && a_point.second-2 >= 0) {
    Point left_up_step1({a_point.first-1, a_point.second-1});
    Point left_up_step2({a_point.first-2, a_point.second-2});
    if (z_points_set.count(left_up_step1) && !z_points_set.count(left_up_step2) && !a_points_set.count(left_up_step2)) {
      return true;
    }
  }
  // right up
  if (a_point.first-2 >= 0 && a_point.second+2 < m) {
    Point right_up_step1({a_point.first-1, a_point.second+1});
    Point right_up_step2({a_point.first-2, a_point.second+2});
    if (z_points_set.count(right_up_step1) && !z_points_set.count(right_up_step2) && !a_points_set.count(right_up_step2)) {
      return true;
    }
  }
  // left down
  if (a_point.first+2 < n && a_point.second-2 >= 0) {
    Point left_down_step1({a_point.first+1, a_point.second-1});
    Point left_down_step2({a_point.first+2, a_point.second-2});
    if (z_points_set.count(left_down_step1) && !z_points_set.count(left_down_step2) && !a_points_set.count(left_down_step2)) {
      return true;
    }
  }
  // right down
  if (a_point.first+2 < n && a_point.second+2 < m) {
    Point right_down_step1({a_point.first+1, a_point.second+1});
    Point right_down_step2({a_point.first+2, a_point.second+2});
    if (z_points_set.count(right_down_step1) && !z_points_set.count(right_down_step2) && !a_points_set.count(right_down_step2)) {
      return true;
    }
  }

  return false;
}

bool may_beat_(const uint16_t n, const uint16_t m, const PointsSet& a_points_set, const PointsSet& z_points_set) {
  for (const auto& a_point : a_points_set) {
    if (a_point_may_beat(n, m, a_point, a_points_set, z_points_set)) {
      return true;
    }
  }
  return false;
}

bool may_beat(const uint16_t n, const uint16_t m, const PointsSet& w_points_set, const PointsSet& b_points_set,
              const std::string turn) {
  if (turn == "white")
    return may_beat_(n, m, w_points_set, b_points_set);
  else
    return may_beat_(n, m, b_points_set, w_points_set);
}

int main() {
//  uint16_t n1 = 8;
//  uint16_t m1 = 8;
//  PointsSet w_points1{{0,0},{1,5},{5,5}};
//  PointsSet b_points1{{1,1},{6,6},{7,7}};
//  std::string turn1 = "white";
//  assert(may_beat(n1, m1, w_points1, b_points1, turn1));
//  return 0;

  uint16_t n, m, w_num;
  std::cin >> n >> m >> w_num;

  PointsSet w_points_set;
  for (uint16_t i = 0; i < w_num; ++i) {
    uint16_t py, px;
    std::cin >> py >> px;
    w_points_set.insert({py-1, px-1});
  }

  uint16_t b_num;
  std::cin >> b_num;
  PointsSet b_points_set;
  for (uint16_t i = 0; i < b_num; ++i) {
    uint16_t py, px;
    std::cin >> py >> px;
    b_points_set.insert({py-1, px-1});
  }

  std::string turn;
  std::cin >> turn;

  auto beat = may_beat(n, m, w_points_set, b_points_set, turn);
  if (beat)
    std::cout << "Yes";
  else
    std::cout << "No";
}
