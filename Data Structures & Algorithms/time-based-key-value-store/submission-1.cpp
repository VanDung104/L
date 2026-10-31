#include <bits/stdc++.h>
using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> data;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = data.find(key);

        if (it == data.end()) {
            return "";
        }

        const auto& history = it->second;

        int left = 0;
        int right = static_cast<int>(history.size()) - 1;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (history[mid].first <= timestamp) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (answer == -1) {
            return "";
        }

        return history[answer].second;
    }
};