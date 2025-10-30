class Bank {
public:
    vector<long long> temp;
    int n;
    bool check(int x) {
        if (x < 1 || x > n) {
            return true;
        }
        return false;
    }
    Bank(vector<long long>& balance) {
        temp = balance;
        n = balance.size();
    }

    bool transfer(int account1, int account2, long long money) {
        if (check(account1) || check(account2)) {
            return false;
        }
        if (temp[account1 - 1] < money) {
            return false;
        } else {
            temp[account1 - 1] -= money;
            temp[account2 - 1] += money;
            return true;
        }
    }

    bool deposit(int account, long long money) {
        if (check(account)) {
            return false;
        }
        temp[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (check(account)) {
            return false;
        }
        if (temp[account - 1] < money) {
            return false;
        } else {
            temp[account - 1] -= money;
            return true;
        }
    }
};

