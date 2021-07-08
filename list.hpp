#ifndef LIST_HPP_
#define LIST_HPP_
//using namespace std;
#include <iostream>

template <typename T>
class List
{
  public:
    class Node; //mówimy że będzie , później rozpiszemy 
    int counter=0; 
    std::shared_ptr<Node> head =nullptr;
    std::shared_ptr<Node> tail =nullptr;
    
    class Node
    {      
      public:
        T value; //wartość
        std::shared_ptr<Node> next; //inteligetny wskaźnik na kolejny element
        std::shared_ptr<Node> before; // inteligentny wskaźnik na wcześniejszy element

        std::shared_ptr<Node> newNode(T nowa)
        {
          std::shared_ptr<Node> X = std::make_shared<Node>();
          X->value = nowa;
          X->next = nullptr;
          X->before = nullptr;
          return X;
        }
    };
    
    class Iterator
    {
      private:
      std::shared_ptr<Node> n_ptr=nullptr;

      public:
        using difference_type = long;
        using value_type = T;
        using pointer = const T*;
        using reference = const T&;
        using iterator_category = std::random_access_iterator_tag;

        Iterator(std::shared_ptr<Node> node = nullptr);

        Iterator operator++();
        Iterator operator--();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        bool operator>(const Iterator& other) const;
        bool operator<(const Iterator& other) const;
        difference_type operator-(const Iterator& other) const;
        Iterator operator+(difference_type diff) const;
        Iterator operator-(difference_type diff) const;
        Iterator operator[](std::size_t i);
        T& operator*();
    };

    class ConstIterator
    {
      private:
      std::shared_ptr<Node> n_ptr=nullptr;

    public:
      using difference_type = long;
      using value_type = T;
      using pointer = const T*;
      using reference = const T&;
      using iterator_category = std::random_access_iterator_tag;

      ConstIterator(std::shared_ptr<Node> node = nullptr);

      ConstIterator operator++();
      ConstIterator operator--();
      bool operator==(const ConstIterator& other) const;
      bool operator!=(const ConstIterator& other) const;
      bool operator>(const ConstIterator& other) const;
      bool operator<(const ConstIterator& other) const;
      difference_type operator-(const ConstIterator& other) const;
      ConstIterator operator+(difference_type diff) const;
      ConstIterator operator-(difference_type diff) const;
      ConstIterator operator[](std::size_t i);
      const T& operator*();
    };

    void pushBack(const T& newElement);
    void pushFront(const T& newElement);
    void insert(const T& newElement, int index);
    void remove(const T& element);
    void remove_first_elem();
    Iterator begin();
    Iterator end();
    ConstIterator cbegin() const;
    ConstIterator cend() const;
    T& operator[](int index);
};

template <typename T>
List<T>::Iterator::Iterator(typename std::shared_ptr<List<T>::Node> node)
{
   n_ptr=node;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator++()
{
  if(n_ptr==nullptr)
  {
    std::cout<<"blad";
    exit(1);
  }

  n_ptr=n_ptr->next;
  return *this;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator--()
{
  if(n_ptr==nullptr)
  {
    std::cout<<"blad";
    exit(1);
  }

  n_ptr=n_ptr->before;
  return *this;
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator& other) const
{
  return n_ptr == other.n_ptr;
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator& other) const
{
    return !(*this==other);
}

template <typename T>
bool List<T>::Iterator::operator>(const Iterator& other) const
{ 
  //Iterator Iter(n_ptr);
  // for( int i=0 ;Iter.n_ptr!=nullptr; i++)
  //   {
  //     if(Iter==other)
  //     {
  //      return false;
  //     }
  //     ++Iter;
  //   }                                                           
    return true;                                              
    /* for( std::shared_ptr<Node> tymczasowy = n_ptr;tymczasowy->next!=nullptr; tymczasowy=tymczasowy->next)
    {
      if(tymczasowy==other.n_ptr)
      {
       return false;                                          
      }
    }                                                        
    return true;*/
}

template <typename T>
bool List<T>::Iterator::operator<(const Iterator& other) const
{
  // Iterator Iter(n_ptr);
  // for( int i=0 ;Iter.n_ptr!=nullptr; i++)
  //   {
  //     if(Iter==other)
  //     {
  //      return false;
  //     }
  //     --Iter;
  //   }
    return true;
  /*for( std::shared_ptr<Node> tymczasowy = n_ptr; tymczasowy->before!=nullptr; tymczasowy=tymczasowy->before)
  {
    if(tymczasowy==other.n_ptr)
    {
      return false;
    }
  }
  return true;*/
}

template <typename T>
typename List<T>::Iterator::difference_type List<T>::Iterator::operator-(const Iterator& other) const
{ 
  int dodatkowa=0;
  auto tymczasowy = (*this>other) ? other.n_ptr : n_ptr;
  for(int i=0;tymczasowy !=nullptr;tymczasowy=tymczasowy->next)
  {
    dodatkowa++;
  }
  return dodatkowa;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator+(difference_type diff) const
{
  //std::shared_ptr<Node> pomocniczy=nullptr;
  //pomocniczy=n_ptr;
  Iterator Iter(n_ptr);
  for(int i=0;i<diff;i++)
  {
    if(n_ptr!=nullptr)
    ++Iter;
    //pomocniczy=pomocniczy->next;
  }
  //return Iter;
  //return Iterator(pomocniczy);
  return Iterator();
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator-(difference_type diff) const
{
  Iterator Iter(n_ptr);
  for(int i=0;i<diff;i++)
  {
    if(n_ptr!=nullptr)
    --Iter;
  }
  //return Iter;
  return Iterator();
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator[](std::size_t i)
{
  std::shared_ptr<Node> dodatkowy(nullptr);
  if(i==0)
    {
      dodatkowy=n_ptr;
    }
  else
    {
      dodatkowy=n_ptr;
      for(int x=0; x<=i; x++)
      {
        dodatkowy=dodatkowy->next;
      }

    }
  return Iterator(dodatkowy);
}

template <typename T>
T& List<T>::Iterator::operator*()
{
    return n_ptr->value;
}





template <typename T>
List<T>::ConstIterator::ConstIterator(std::shared_ptr< List<T>::Node> node)
{
  n_ptr=node;
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator++()
{
  return ConstIterator(n_ptr->next);
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator--()
{
  return ConstIterator(n_ptr->before);
}

template <typename T>
bool List<T>::ConstIterator::operator==(const ConstIterator& other) const
{
  if(n_ptr == other.n_ptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T>
bool List<T>::ConstIterator::operator!=(const ConstIterator& other) const
{
  if(n_ptr != other.n_ptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T>
bool List<T>::ConstIterator::operator>(const ConstIterator& other) const
{
  Iterator Iter(n_ptr);
  for( int i=0 ;Iter.n_ptr!=nullptr; i++)
    {
      if(Iter==other)
      {
       return false;
      }
      ++Iter;
    }                                                           
    return true;    
  // for(auto tymczasowy = n_ptr;tymczasowy!=nullptr; tymczasowy=tymczasowy->next)
  // {
  //   if(tymczasowy==other.n_ptr)
  //   {
  //     return false;
  //   }
  // }
}

template <typename T>
bool List<T>::ConstIterator::operator<(const ConstIterator& other) const
{
  Iterator Iter(n_ptr);
  for( int i=0 ;Iter.n_ptr!=nullptr; i++)
    {
      if(Iter==other)
      {
       return false;
      }
      --Iter;
    }
    return true;
  // for(auto tymczasowy = n_ptr;tymczasowy!=nullptr; tymczasowy=tymczasowy->next)
  // {
  //   if(tymczasowy==other.n_ptr)
  //   {
  //     return true;
  //   }
  // }
}

template <typename T>
typename List<T>::ConstIterator::difference_type List<T>::ConstIterator::operator-(const ConstIterator& other) const
{
  int dodatkowa=0;
  auto tymczasowy = (*this>other) ? other.n_ptr : n_ptr;

  for(;tymczasowy !=nullptr;tymczasowy=tymczasowy->next)
  {
    dodatkowa++;
  }
  return dodatkowa;
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator+(difference_type diff) const
{
  ConstIterator Iter(n_ptr);
  for(int i=0;i<diff;i++)
  {
    if(n_ptr!=nullptr)
    ++Iter;
  }
  //return Iter;
  return Iterator();
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator-(difference_type diff) const
{
  ConstIterator Iter(n_ptr);
  for(int i=0;i<diff;i++)
  {
    if(n_ptr!=nullptr)
    --Iter;
  }
  //return Iter;
  return Iterator();
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator[](std::size_t i)
{
  std::shared_ptr<Node> dodatkowy(nullptr);
  if(i==0)
    {
      dodatkowy=n_ptr;
    }
  else
    {
      dodatkowy=n_ptr;
      for(int x=0; x<i; x++)
      {
        dodatkowy=dodatkowy->next;
      }   
    }
  return Iterator(dodatkowy);
}

template <typename T>
const T& List<T>::ConstIterator::operator*()
{
    
    return n_ptr->value;
    
}









template <typename T>
void List<T>::pushBack(const T& newElement)
{
  Node N;
  std::shared_ptr<Node> dodatkowy = N.newNode(newElement);      //inteligentny wskaźnik zawierający odpowiednia wartość 
  if(head==nullptr)                                            //kiedy lista jest pusta
  {
    head=dodatkowy;
    tail=dodatkowy;
  }
  else 
  {

    std::shared_ptr<Node> jump(nullptr);                      //dodatkowy inteligentny wskaznik aby mozna było z łatwością poruszać po liscie i nic w niej nie zienic
    jump = head;
    for(int i=0; jump->next != nullptr; i++)                 // do momentku napotkania konca listy 
    {
      jump = jump->next;                                   //przejscie na kolejny element 

    }
    jump->next = dodatkowy;                              // dodanie nowego elementu
    tail=dodatkowy;
  }
  counter++;                                           //dodajemy do warotosci ilosci elementow listy 
}
template <typename T>
void List<T>::pushFront(const T& newElement)
{
  Node N;
  std::shared_ptr<Node> dodatkowy = N.newNode(newElement);                  //dodatkowy inteligentny wskaznik aby mozna było z łatwością poruszać po liscie i nic w niej nie zienic
  if(head==nullptr)                                                        //kiedy lista jest pusta 
  {
    head=dodatkowy; 
    tail=dodatkowy;
  }
  else
  {
    dodatkowy->next =head;
    head->before = dodatkowy;
    head = dodatkowy;                                                 //nowy head
  }
  counter ++;                                                        //dodajemy do wartości ilosci elementów listy 

}
template <typename T>
void List<T>::insert(const T& newElement, int index)
{
  Node N;
  std::shared_ptr<Node> dodatkowy =N.newNode(newElement);
  if(index==0)                                                            // przypadek 1. kiedy jestesmy na poczatku listy 
  {
    pushFront(newElement);
  }
  else
  {
    if(index==counter)                                                    // przypadek 2. kiedy jestesmy na koncu listy 
    {
      pushBack(newElement);
    }
    else
    {
      if(index < 0 )                                                     // przypadek 3. kiedy index jest ujemny 
      {
          std::cout<<"Błąd w podawaniu instrukcji \n ";
          exit(1);
      }
      else
      {
        if(index>counter)                                               // przypadek 4. kiedy wybrany index nie nalezy do listy 
        {
          std::cout<<"wychodzimy poza liste \n ";
          exit(1);
        }
        else                                                           // przypadek 5. kiedy index znajduje sie w srodku listy 
        {
          std::shared_ptr<Node> jump(nullptr);                       //pomocnicy aby łatwiej było sie poruszac po liscie                       
          jump=head;
          for(int i=0; i<index-1; i++)
          {
            jump=jump->next;
          }
          dodatkowy->next = jump->next;
          dodatkowy->before = jump;

          dodatkowy->next->before=dodatkowy; 

          jump->next=dodatkowy;
          counter++;                                            //dodanie  do wartosci ilosci elementow listy  
          
        }
      }
    }
  }
}

template <typename T>
void List<T>::remove(const T& element)
{
  std::shared_ptr<Node> pomocniczy=nullptr;                  //dodatkowy inteligentny wskaznik aby mozna było z łatwością poruszać po liscie i nic w niej nie zienic                      
  if(head->value==element)
  {
    remove_first_elem();                                    //nowa funkcja napisana nizej 
  }
  auto tmp = head;
  while(tmp)                                               // != nullptr
    {
      if(tmp->next && tmp->next->value == element)        // sprawdzamyy przez elemen poprzedzajacy element sprawdzajacy 
        {
          tmp->next = tmp->next->next;
          
        }
      tmp = tmp->next;
    }
  counter--;
}
template <typename T>
void List<T>::remove_first_elem()
{
  if(counter==0)
  {
    std::cout<<"Struktura jest pusta nie mozna usunąć elementu\n";
    exit(1);
  }
  else
  {
    std::shared_ptr<Node> pomocniczy=nullptr;                 //dodatkowy inteligentny wskaznik aby mozna było z łatwością poruszać po liscie i nic w niej nie zienic
    pomocniczy=head;
    head=pomocniczy->next;
    //pomocniczy->next->before=pomocniczy->before;
    
    pomocniczy->next=nullptr;
    pomocniczy->before=nullptr;

  }
  counter--;
}

template <typename T>
typename List<T>::Iterator List<T>::begin()
{

    // TODO: implement
    return Iterator(head);
}

template <typename T>
typename List<T>::Iterator List<T>::end()
{
    // TODO: implement
    return Iterator(tail->next);
}

template <typename T>
typename List<T>::ConstIterator List<T>::cbegin() const
{

    return ConstIterator(head);
}

template <typename T>
typename List<T>::ConstIterator List<T>::cend() const
{
    return ConstIterator(tail->next);
}

template <typename T>
T& List<T>::operator[](int index)
{
  static T element;
  std::shared_ptr<Node> dodatkowy(nullptr);                 //dodatkowy inteligentny wskaznik aby mozna było z łatwością poruszać po liscie i nic w niej nie zienic
  if(index==0)
    {
      dodatkowy=head;
    }
  else
    {
      dodatkowy=head;
      for(int x=0; x<index; x++)
      {
        dodatkowy=dodatkowy->next;
      }   
    }
  element=dodatkowy->value;
  return element;
}

#endif /* LIST_HPP_ */
