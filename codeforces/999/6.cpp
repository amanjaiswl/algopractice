#include <bits/stdc++.h>
using namespace std;

// Function to parse a string into blocks
vector<pair<char, int>> parse_blocks(const string &str) {
  vector<pair<char, int>> blocks;
  if (str.empty())
    return blocks;
  char current_char = str[0];
  int count = 1;
  for (int i = 1; i < str.length(); i++) {
    if (str[i] == current_char) {
      count++;
    } else {
      blocks.emplace_back(make_pair(current_char, count));
      current_char = str[i];
      count = 1;
    }
  }
  blocks.emplace_back(make_pair(current_char, count));
  return blocks;
}

// Function to compute minimal swaps
int compute_min_swaps(const vector<pair<char, int>> &s_blocks) {
  int ones_before = 0;
  int total_swaps = 0;
  for (auto &block : s_blocks) {
    if (block.first == '1') {
      ones_before++;
    } else if (block.first == '0') {
      total_swaps += ones_before;
    }
  }
  return total_swaps;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int test_cases;
  cin >> test_cases;
  while (test_cases--) {
    string s, t_str;
    cin >> s >> t_str;

    if (s.length() != t_str.length()) {
      // Lengths mismatch, which shouldn't happen per problem statement
      cout << "-1\n";
      continue;
    }

    // Parse s and t into blocks
    vector<pair<char, int>> s_blocks = parse_blocks(s);
    vector<pair<char, int>> t_blocks = parse_blocks(t_str);

    // Extract t's required blocks (ignore '?')
    // Since in the sample input, t contains only '0' and '1', this step remains
    // the same If t can contain '?', you would need to adjust accordingly
    vector<pair<char, int>> t_required_blocks;
    for (auto &block : t_blocks) {
      if (block.first != '?') {
        t_required_blocks.emplace_back(block);
      }
    }

    // Count required '0's and '1's
    long long required_zeros = 0, required_ones = 0;
    int required_zero_blocks = 0, required_one_blocks = 0;
    for (auto &block : t_required_blocks) {
      if (block.first == '0') {
        required_zeros += block.second;
        required_zero_blocks++;
      } else if (block.first == '1') {
        required_ones += block.second;
        required_one_blocks++;
      }
    }

    // Count available '0's and '1's in s
    long long available_zeros = 0, available_ones = 0;
    int available_zero_blocks = 0, available_one_blocks = 0;
    for (auto &block : s_blocks) {
      if (block.first == '0') {
        available_zeros += block.second;
        available_zero_blocks++;
      } else if (block.first == '1') {
        available_ones += block.second;
        available_one_blocks++;
      }
    }

    // Feasibility Checks
    bool feasible = true;
    if (available_zeros < required_zeros || available_ones < required_ones) {
      feasible = false;
    }
    if (available_zero_blocks < required_zero_blocks ||
        available_one_blocks < required_one_blocks) {
      feasible = false;
    }

    // Additional Check: Ensure that 't's required blocks can be formed from
    // 's's blocks without merging or splitting Since swapping only rearranges
    // blocks, the required blocks in 't' must correspond to a grouping of 's's
    // blocks

    // To handle this, for each required block in 't', ensure that 's' has at
    // least one block of the same character with length >= required length
    // Alternatively, accumulate blocks in 's' to cover 't's blocks

    // Implementing this logic
    // Create separate lists for '0' and '1' blocks in 's'
    vector<int> s_zero_lengths, s_one_lengths;
    for (auto &block : s_blocks) {
      if (block.first == '0')
        s_zero_lengths.push_back(block.second);
      else
        s_one_lengths.push_back(block.second);
    }

    // Similarly, create required lists for '0' and '1' blocks in 't'
    vector<int> t_zero_lengths, t_one_lengths;
    for (auto &block : t_required_blocks) {
      if (block.first == '0')
        t_zero_lengths.push_back(block.second);
      else
        t_one_lengths.push_back(block.second);
    }

    // Now, for each required block in 't', check if 's' has at least one block
    // of the same character with length >= required length Since blocks cannot
    // be merged or split, the number of blocks must match exactly

    bool size_feasible = true;
    // Check for '0's
    if (t_zero_lengths.size() > s_zero_lengths.size()) {
      size_feasible = false;
    } else {
      // Sort both lists in non-decreasing order
      sort(s_zero_lengths.begin(), s_zero_lengths.end(), greater<int>());
      sort(t_zero_lengths.begin(), t_zero_lengths.end(), greater<int>());
      for (int i = 0; i < t_zero_lengths.size(); i++) {
        if (s_zero_lengths[i] < t_zero_lengths[i]) {
          size_feasible = false;
          break;
        }
      }
    }

    // Check for '1's
    if (t_one_lengths.size() > s_one_lengths.size()) {
      size_feasible = false;
    } else {
      sort(s_one_lengths.begin(), s_one_lengths.end(), greater<int>());
      sort(t_one_lengths.begin(), t_one_lengths.end(), greater<int>());
      for (int i = 0; i < t_one_lengths.size(); i++) {
        if (s_one_lengths[i] < t_one_lengths[i]) {
          size_feasible = false;
          break;
        }
      }
    }

    if (!size_feasible) {
      feasible = false;
    }

    if (!feasible) {
      cout << "-1\n";
      continue;
    }

    // Compute minimal swaps
    int total_swaps = compute_min_swaps(s_blocks);
    cout << total_swaps << '\n';
  }
}
