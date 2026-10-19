class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Bước 1: Sắp xếp mảng trọng lượng tăng dần
        sort(people.begin(), people.end());
        
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;
        
        // Bước 2: Dùng hai con trỏ ghép cặp người nặng nhất và nhẹ nhất
        while (left <= right) {
            // Nếu người nhẹ nhất và người nặng nhất có tổng cân nặng <= limit -> đi chung một thuyền
            if (people[left] + people[right] <= limit) {
                left++;  // Đưa người nhẹ lên thuyền
            }
            
            // Người nặng nhất luôn luôn phải lên thuyền (dù đi chung hay đi một mình)
            right--; 
            
            // Tốn thêm 1 chiếc thuyền cho lượt này
            boats++;
        }
        
        return boats;
    }
};