
/*3, 5, 2, 8, 1, 7, 6, 0 , 3,, 9

pivot = 5 
 
output : 3, 2, 1, 0, 3, 5, 8, 7, 6, 9
 */
void Rearrange(vector<int>& v, int pivot)
{
    vector<int> tmp;
    vector<int> ret;
    for(int x : v){
        if(x < pivot){
            tmp.push_back(x);
        }
    }

    // std::sort(tmp);
    tmp.clear();

    for(int i = 0; i < tmp.size(); i++){
        ret.push_back(tmp[i]);
        
    }

    ret.push_back(pivot);
    for(int x : v){
        if(x > pivot){
            tmp.push_back();
        }
    }

    // std::sort(tmp);
    for(int i = 0; i < tmp.size(); i++){
        ret.push_back(tmp[i]);
    }



}
