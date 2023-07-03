template<typename T>
struct FenwickTree{
   vector<T> bit;
   int n;
   void construct(vector<T> const &a){
      this->n = a.size();
      bit.assign(n+1,0);
      for(int i=1; i<=n; ++i)
         update(i,a[i-1]);
   }
   T sum(int r) {
      T ret = 0;
      for(; r>0; r-=r&-r)
         ret += bit[r];
      return ret;
   }
   T sum(int l, int r) {
      return sum(r)-sum(l - 1);
   }
   void update(int idx,T delta) {
      for(; idx<=n; idx+=idx&-idx)
         bit[idx] += delta;
   }
   void range_update(int l,int r,T delta){
      update(l,delta);
      update(r+1,-delta);
   }
};
class NumArray {
private:
    FenwickTree<int> ft;
    vector<int> v;
public:
    NumArray(vector<int>& nums) {
        v = nums;
        ft.construct(nums);
    }
    
    void update(int index, int val) {
        ft.update(index+1,val-v[index]);
        v[index] = val;
    }
    
    int sumRange(int left, int right) {
        return ft.sum(left+1,right+1);
    }
};