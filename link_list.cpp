#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

struct node
{
    float rating;
    string review;
    node *next;
};
class ResturantReviewList
{
private:
    node *head, *tail;

public:
    ResturantReviewList()
    {
        head = NULL;
        tail = NULL;
    }
    void add_node_head()
    {
        float rating;
        string review;

        node *temp = new node;
        cout << "Enter the rating (0-5): ";
        cin >> rating;
        if (rating >= 0 and rating <= 5)
        {
            cout << "Enter review message:";
            cin >> review;
            temp->rating = rating;
            temp->review = review;
            temp->next = NULL;

            if (head == NULL)
            {
                head = temp;
            }
            else
            {
                temp->next = head;
                head = temp;
            }
        }
        else{
            cout<<endl<<"Rating should be in range 0 to 5"<<endl;
            add_node_head();
        }
    }
    void add_node_tail()
    {
        float rating;
        string review;

        node *temp = new node;
        cout << "Enter the rating: ";
        cin >> rating;
        if (rating >= 0 and rating <= 5)
        {
            cout << "Enter review message:";
            cin >> review;
            temp->rating = rating;
            temp->review = review;
            temp->next = NULL;
            if (tail == NULL)
            {
                tail = temp;
            }
            else
            {
                temp->next = tail;
                tail = temp;
            }
        }
        else
        {
            cout<<endl<<"Rating should be in range 0 to 5"<<endl;
            add_node_tail();
        }
    }
    void display_reviews_head()
    {
        node *temp;
        temp = head;
        cout << endl
             << "Outputting all reviews" << endl;
        while (temp != NULL)
        {
            int count = 1;
            cout << endl
                 << "Review #" << count << " : " << temp->rating << " : " << temp->review << endl;
            temp = temp->next;
        }
    }

    void display_reviews_tail()
    {
        node *temp;
        temp = tail;
        cout << endl
             << "Outputting all reviews" << endl;
        while (temp != NULL)
        {
            int count = 1;
            cout << endl
                 << "Review #" << count << " : " << temp->rating << " : " << temp->review << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    ResturantReviewList resturant;
    int choice;
    while (1)
    {
        cout << endl
             << "Which link list method should we use ? ";
        cout << endl
             << "\t [1] New nodes are added at the head of link list.";
        cout << endl
             << "\t [2] New nodes are added at the tail of link list.";
        cout << endl
             << "\t Choice ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            resturant.add_node_head();
            while (1)
            {
                char review_choice;
                cout << endl
                     << "Enter another review ? Y/N ";
                cin >> review_choice;
                if (toupper(review_choice) == 'Y')
                {
                    resturant.add_node_head();
                }
                else if (toupper(review_choice) == 'N')
                {
                    resturant.display_reviews_head();
                    exit(1);
                }
                else
                {
                    cout << endl
                         << "Wrong Choice";
                }
            }

            break;
        case 2:
            resturant.add_node_tail();
            while (1)
            {
                char review_choice;
                cout << "Enter another review ? Y/N ";
                cin >> review_choice;
                if (toupper(review_choice) == 'Y')
                {
                    resturant.add_node_tail();
                }
                else if (toupper(review_choice) == 'N')
                {
                    resturant.display_reviews_tail();
                    exit(1);
                }
                else
                {
                    cout << endl
                         << "Wrong Choice";
                }
            }
            break;

        default:
            cout << "Enter the valid choice";
        }
    }
    return 0;
}