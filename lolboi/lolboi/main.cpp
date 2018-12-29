//
//  main.cpp
//  lolboi
//
//  Created by Avinash Swaminathan on 06/08/18.
//  Copyright © 2018 Avinash Swaminathan. All rights reserved.
//

#include <queue>
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* back;
};
void swap(int &a,int &b){
    int t=a;a=b;b=t;
}
Node* Insert(Node* begin,int data)
{   Node* temp=begin;
    if(begin==NULL) {begin=new Node;
        begin->data=data;
        begin->next=NULL;
        begin->back=NULL;
                    return begin;}
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=new Node;
    temp->next->back=temp;
    temp->next->next=NULL;
    temp->next->data=data;
    return begin;
}
void display(Node* start){
    while(start->next!=NULL)
        {cout<<start->data<<"->";
        start=start->next;}
    cout<<start->data;
}
Node* QuickSort(Node* start,Node* end)
{
    if(start==end) return start;
    Node* pivot=start;
    
    Node* traverse=start;
    Node* temp=start;
    
    while(traverse!=NULL){
        if(traverse->data<=pivot->data)
        {
            temp=temp->next;
            swap(temp->data,traverse->data);
        }
        cout<<traverse->data;
        traverse=traverse->next;
    }
    cout<<endl;
    swap(temp->data,pivot->data);
    if(temp==start) temp->next=QuickSort(temp->next, end);
    else if(temp==end) start=QuickSort(start, temp->back);
    else{
        temp->next=QuickSort(temp->next, end);
        start=QuickSort(start, temp->back);
    }
    return start;
}
int main() {
    // insert code here...
    Node* start=NULL;
    start=Insert(start, 5);
    start=Insert(start, 4);
    start=Insert(start, 9);
    start=Insert(start, 8);
     start=Insert(start, 7);
    Node* temp=start;
    while(temp->next!=NULL)
        temp=temp->next;
    start=QuickSort(start, temp);
    cout<<start->data;
    //cout<<start->data;
}
