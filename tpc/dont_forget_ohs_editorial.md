We need to calculate a future date given N days from March 10, 2024 and find what day of the week it falls on.

First, let's define the arrays we'll need:

```cpp
string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
```

Instead of checking every single year for leap years, we can use a 4-year period:
- 4 years = 1461 days (because there's 1 leap day in those 4 years)
- We can jump ahead by 4-year chunks: `year += (N / 1461) * 4`
- After this, we only have at most 1460 days left to simulate

For the remaining days, we just simulate day by day:
1. Add 1 to the day
2. Check if the day is too big for the current month
3. If yes, reset day to 1 and go to next month
4. If month > 12, reset month to 1 and go to next year
5. For leap years, add an extra day to February when `year % 4 == 0`

```cpp
void solve() {
    int N;
    cin >> N;
    int year = 2024, month = 3, day = 10, period = 1461, n = N;
    
    // jump ahead by 4-year periods
    year += n / period * 4;
    n %= period;
    
    // simulate the rest day by day
    for (int i = 0; i < n; ++i) {
        day++;
        // months array is 0-indexed so [month - 1]
        // year % 4 == 0 -> this is a leap year
        // if month is 2, February is 29 instead of 28
        if (day > (months[month - 1] + (month == 2 && year % 4 == 0))) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
    
    auto f = [](int x) {
        if (x > 9) return to_string(x);
        return '0' + to_string(x);
    };
    
    cout << f(day) << '.' << f(month) << '.' << year << ' ' << days[N % 7] << '\n';
}
```