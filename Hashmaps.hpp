#include<string>
using namespace std;
template<typename T>
class MapNode{
    public:
    string key;
    T value;
    MapNode * next;
    MapNode(string key, T value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode(){
        delete next;
    }
};




template<typename T>
class Ourmap{
   
    MapNode<T> ** buckets = NULL;
    int count;
    int numbuckets = 5;
   
    int Getbucketindex(string key){
        int hashcode = 0;
        int currentcoeff = 1;
        for(int i = key.length(); i > 0 ; i--){
            hashcode+= key[i] * currentcoeff;
            hashcode = hashcode % numbuckets;
            currentcoeff = currentcoeff * 37;
            currentcoeff = currentcoeff %numbuckets;
            }
        return hashcode % numbuckets; 
    }

    void rehash(){
        MapNode<T>** temp = buckets;
        buckets = new MapNode<T>*[numbuckets*2];
        for(int i = 0 ; i < numbuckets*2 ; i++){
            buckets[i] = NULL;
        }

        int oldbucketcount = count;
        numbuckets = numbuckets * 2;
        count = 0  ;
        for(int i = 0 ; i < oldbucketcount; i++){
            MapNode<T> * head =temp[i];
            while(head != NULL){
                std::string key = head->key ;
                T value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
           for(int i = 0 ; i < oldbucketcount ; i++){
                MapNode<T>* head = temp[i];
                delete head;
            }
            delete [] temp;
            return;
    }
         public:
        Ourmap(){
            count = 0 ;
            buckets = new MapNode<T>*[numbuckets];
            for(int i = 0 ; i < numbuckets; i++)
            buckets[i] = NULL;
        }
        ~Ourmap(){
            for(int i = 0 ; i < numbuckets; i++)
             delete buckets[i];
             delete [] buckets;
        }
        int size(){
            return count;
        }

        void insert(string key, T value){
            int bucketindex = Getbucketindex(key);
            MapNode<T> * head = buckets[bucketindex];
            while(head!=NULL){
                if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketindex];
        MapNode<T> * node = new MapNode<T>(key,value);
        node->next = head;
        buckets[bucketindex] = node;
        count++;
        double loadfactor = 1.0 * count /numbuckets;
        if(loadfactor > 0.7)
            rehash();
         return;
        }

        T remove(string key){
            int bucketindex = Getbucketindex(key);
            MapNode<T>* head = buckets[bucketindex];
            MapNode<T> prv = NULL;
            while(head!=NULL){
                if(head->key == key){
                    if(prv==NULL){
                        buckets[bucketindex] = head->next;
                    }
                    prv->next = head->next;
                    head->next = NULL;
                    T value = head->value;
                    delete head;
                    count--;
                    return value;
                }
                prv = head;
                head = head->next;
            }
            return 0 ;
        }
        T getvalue(string key){
            int bucketindex = Getbucketindex(key);
            MapNode<T> * head = buckets[bucketindex];
            while(head!= NULL){
                if(head->key == key){
                    return head->value;
                }
            }
            return 0;
        }

        double Getloadfactor(){
            return 1.0* count/numbuckets;
        }
};