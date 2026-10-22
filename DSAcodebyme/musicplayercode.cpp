#include<iostream>
#include<string>
using namespace std;

class song{
	public:
		song *prev;
		song *next;
		string title;
		string artist;

		song(string x,string y)
		{
			prev=NULL;
			next=NULL;
			title=x;
			artist=y;
		}
};

class playlist{
	private:
		song *head;
	public:
		song *current;

		playlist()
		{
			head=NULL;
			current=NULL;
		}

		int empty()
		{
			if(head==NULL)
				return 1;
			else
				return 0;
		}

		void insert(string x,string y)
		{
			song *p=new song(x,y);

			if(empty())
			{
				head=p;
				current=head;
			}
			else
			{
				song *q=head;

				while(q->next!=NULL)
					q=q->next;

				q->next=p;
				p->prev=q;
			}
		}

		void remove(string x)
		{
			if(empty())
			{
				cout<<"Playlist is Empty"<<endl;
				return;
			}

			song *q=head;

			while(q!=NULL && q->title!=x)
				q=q->next;

			if(q==NULL)
			{
				cout<<"Song Not Found in playlist"<<endl;
				return;
			}

			if(q->prev!=NULL)
				q->prev->next=q->next;
			else
				head=q->next;

			if(q->next!=NULL)
				q->next->prev=q->prev;

			if(current==q)
			{
				if(q->next!=NULL)
					current=q->next;
				else
					current=q->prev;
			}

			delete q;
			cout<<"Song Deleted Successfully"<<endl;
		}

		void play(string x)
		{
			if(current==NULL)
			{
				cout<<"Playlist is Empty"<<endl;
				return;
			}

			if(x=="next")
			{
				if(current->next==NULL)
				{
					cout<<"Last Song (Cannot play next)"<<endl;
					return;
				}
				else
					current=current->next;
			}

			else if(x=="previous")
			{
				if(current->prev==NULL)
				{
					cout<<"First Song (Cannot play previous)"<<endl;
					return;
				}
				else
					current=current->prev;
			}

			cout<<"Current Song playing: "<<current->title<<endl;
		}

		void playCompletePlaylist()
		{
			if(empty())
			{
				cout<<"Playlist is Empty"<<endl;
				return;
			}

			song *q=head;

			while(q!=NULL)
			{
				current=q;
				cout<<"Current Song playing: "<<q->title<<endl;
				q=q->next;
			}
		}

		void repeatAll(int repetitions)
		{
			if(empty())
			{
				cout<<"Playlist is Empty"<<endl;
				return;
			}

			for(int i=1;i<=repetitions;i++)
			{
				cout<<"Repetition "<<i<<":"<<endl;
				playCompletePlaylist();
			}
		}

		void displayforward()
		{
			if(empty())
			{
				cout<<"Playlist is Empty"<<endl;
				return;
			}

			song *q=head;
			cout<<"Forward Display:"<<endl;

			while(q!=NULL)
			{
				cout<<q->title<<"<=>";
				q=q->next;
			}
			cout<<endl;
		}

		void displaybackward()
		{
			if(empty())
			{
				cout<<"Playlist is Empty"<<endl;
				return;
			}

			song *q=head;

			while(q->next!=NULL)
				q=q->next;

			cout<<"Backward Display:"<<endl;

			while(q!=NULL)
			{
				cout<<q->title<<"<=>";
				q=q->prev;
			}
			cout<<endl;
		}

		~playlist()
		{
			while(head!=NULL)
			{
				song *q=head;
				head=head->next;
				delete q;
			}
		}
};

int main()
{
	playlist p;
	int choice;
	string title,artist;

	do
	{
		cout<<"===== MUSIC PLAYLIST ====="<<endl;
		cout<<"1. Add Song"<<endl;
		cout<<"2. Delete Song"<<endl;
		cout<<"3. Display Playlist in Forward"<<endl;
		cout<<"4. Display Playlist in Reverse"<<endl;
		cout<<"5. Play Current Song"<<endl;
		cout<<"6. Play Next Song"<<endl;
		cout<<"7. Play Previous Song"<<endl;
		cout<<"8. Play Complete Playlist"<<endl;
		cout<<"9. Repeat All"<<endl;
		cout<<"10. Show Current Song"<<endl;
		cout<<"11. Exit"<<endl;

		cout<<"Enter your choice: ";
		cin>>choice;
		cout<<endl;

		switch(choice)
		{
			case 1:
				cout<<"Enter song title: ";
				cin>>title;

				cout<<"Enter artist name: ";
				cin>>artist;

				p.insert(title,artist);
				break;

			case 2:
				cout<<"Enter song title to delete: ";
				cin>>title;
				p.remove(title);
				break;

			case 3:
				p.displayforward();
				break;

			case 4:
				p.displaybackward();
				break;

			case 5:
				p.play("current");
				break;

			case 6:
				p.play("next");
				break;

			case 7:
				p.play("previous");
				break;

			case 8:
				p.playCompletePlaylist();
				break;

			case 9:
			{
				int repetitions;
				cout<<"Enter number of repetitions: ";
				cin>>repetitions;
				p.repeatAll(repetitions);
				break;
			}

			case 10:
				p.play("current");
				break;

			case 11:
				cout<<"Exiting..."<<endl;
				break;

			default:
				cout<<"Invalid choice!"<<endl;
		}

		cout<<endl;

	}while(choice!=11);

	return 0;
}/*
PS C:\SCS\Ram\Desktop\Tejaswini\VS CODE> g++ menudriven.cpp -o menudriven.exe                        
PS C:\SCS\Ram\Desktop\Tejaswini\VS CODE> .\menudriven.
===== MUSIC PLAYLIST =====
1. Add Song
2. Delete Song
3. Display Playlist in Forward
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 1

Enter song title: sanam
Enter artist name: arjit

===== MUSIC PLAYLIST =====
1. Add Song
2. Delete Song
3. Display Playlist in Forward
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice:


PS C:\SCS\Ram\Desktop\Tejaswini\VS CODE>
*/