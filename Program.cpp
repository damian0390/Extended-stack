#include <iostream>
#include <stack>

template<class T>
class MyStack : public std::stack<T>{

  public:

    void push_to_down(T new_elem){
      reverse_to_temp();
      this -> push(new_elem);
      reverse_back();
    }

    void pop_from_down(){
      if (this -> empty()){
        std::cout<<"stack is empty"<<std::endl;
        return;
      }
      reverse_to_temp();
      temp.pop();
      reverse_back();
    }

    T get_from_down(){
      T res;
      if (this -> empty()) std::cout<<"stack is empty"<<std::endl;
      reverse_to_temp();
      res = temp.top();
      reverse_back();
      return res;
    }

    void push_to_position(T new_elem, int position){

      if (this -> size() < position){
        std::cout<<"Stack has not as many elements"<<std::endl;
        return;
      }
      
      reverse_to_temp();
      
      while(!temp.empty()){
        if (this -> size() == position - 1) this -> push(new_elem);
        this -> push(temp.top());
        temp.pop();
      }
    } //push_to_position

    void pop_from_position(int position){

      if (this -> size() < position){
        std::cout<<"Stack has not as many elements"<<std::endl;
        return;
      }
            
      reverse_to_temp();

      bool popped = false;
      while(!temp.empty()){
        if (this -> size() == position - 1 && !popped){
          temp.pop();
          popped = true;
          continue;
        }
        this -> push(temp.top());
        temp.pop();
      }
    }  //pop_from_position

    T get_from_position(int position){

      if (this -> size() < position){
        std::cout<<"Stack has not as many elements, returned top position"<<std::endl;
        return this -> top();
      }
            
      reverse_to_temp();

      T res;
      while(!temp.empty()){
        this -> push(temp.top());
        if (this -> size() == position) res = this -> top();
        temp.pop();
      }
      return res;
    } //get_from_position

    void reverse_to_temp(){
      while(!this -> empty()){
        temp.push(this -> top());
        this -> pop();
        }
    }

    void reverse_back(){
      while(!temp.empty()){
        this -> push(temp.top());
        temp.pop();
      }
    }

  private:
    std::stack<T> temp;
};

int main() {
  MyStack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push_to_down(9);
  std::cout<<st.get_from_position(1);
  st.pop_from_down();
  std::cout<<st.get_from_down();
  
}
