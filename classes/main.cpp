/*
Name: Nathan Zhou
Date: 11-16-22

Creates a database of media, including video games, music, and movies. Allows for addition, searching,
and deletion of items.

 */


#include <iostream>
#include <cstring>
#include <vector>
#include "parent.h"
#include "videogame.h"
#include "music.h"
#include "movie.h"

const bool TITLE = 0;
const bool YEAR = 1;

void addMedia(std::vector<Parent*>& database) { //add an element of the requested class using their constructors
  char input[10];
  char* title = new char[20];
  int year;
  std::cout << "Media type (VIDEOGAME, MUSIC, MOVIE):\n"; //prompt for media type, title, year
  std::cin >> input;
  std::cout << "Enter the title:\n";
  std::cin.get(title, 19);
  std::cin.get();
  std::cout << "Enter the year:\n";
  std::cin >> year;
  
  if (strncmp(input, "VIDEOGAME", 9) == 0) { //entering video game, also requires publisher, rating
    char* publisher = new char[20];
    char* rating = new char[5];
    std::cout << "Enter the video game publisher:\n";
    std::cin.get(publisher, 19);
    std::cin.get();
    std::cout << "Enter the video game rating:\n";
    std::cin >> rating;
    database.push_back(new VideoGame(title, year, publisher, rating));
    
  }
  if (strncmp(input, "MUSIC", 5) == 0) { //entering music, also requires artist, duration, publisher
    char* artist = new char[20];
    int duration;
    char* publisher = new char[20];
    std::cout << "Enter the music artist:\n";
    std::cin.get(artist, 19);
    std::cin.get();
    std::cout << "Enter the music duration:\n";
    std::cin >> duration;
    std::cout << "Enter the music publisher:\n";
    std::cin.get(publisher, 19);
    std::cin.get();
    database.push_back(new Music(title, year, artist, duration, publisher));
  }
  if (strncmp(input, "MOVIE", 5) == 0) { //entering movie, also requires director, duration, rating
    char* director = new char[20];
    int duration;
    char* rating = new char[5];
    std::cout << "Enter the movie director:\n";
    std::cin.get(director, 19);
    std::cin.get();
    std::cout << "Enter the movie duration:\n";
    std::cin >> duration;
    std::cout << "Enter the movie rating:\n";
    std::cin >> rating;
    database.push_back(new Movie(title, year, director, duration, rating));
  }
}

void searchMedia(std::vector<Parent*>& database) { //given a title or year, search for matches and print their fields
  char input[10];
  char title[20];
  int year;
  bool field = TITLE; //search field
  std::cout << "Search field (TITLE/YEAR):\n";
  std::cin >> input;
  std::cout << "Search query:\n";
  if (strncmp(input, "TITLE", 5) == 0) { //take in title
    std::cin.get(title, 19);
    std::cin.get();
  }
  if (strncmp(input, "YEAR", 4) == 0) { //take in year
    std::cin >> year;
    field = YEAR;
  }
  for (std::vector<Parent*>::iterator it = database.begin(); it != database.end(); ++it) {
    if ((!field && strcmp((*it)->getTitle(),title) == 0) //title search
	|| field && (*it)->getYear() == year) { //year search
      std::cout << "---------------\n";
      if (strcmp((*it)->getType(), "VIDEOGAME") == 0) { //cast and display videogame info
	VideoGame* videogame = static_cast<VideoGame*>(*it);
	std::cout << "VIDEOGAME\n title: " << videogame->getTitle() << "\n year: " << videogame->getYear() << "\n publisher: "
		  << videogame->getPublisher() << "\n rating: " << videogame->getRating() << "\n";
      }
      else if (strcmp((*it)->getType(), "MUSIC") == 0) { //cast and display music info
	Music* music = static_cast<Music*>(*it);
	std::cout << "MUSIC\n title: " << music->getTitle() << "\n artist: " << music->getArtist() << "\n year: "
		  << music->getYear() << "\n duration: " << music->getDuration()
		  << "\n publisher: " << music->getPublisher() << "\n";
      }
      else { //cast and display movie info
	Movie* movie = static_cast<Movie*>(*it);
	std::cout << "MOVIE\n title: " << movie->getTitle() << "\n director: " << movie->getDirector() << "\n year: "
		  << movie->getYear() << "\n duration: " << movie->getDuration() << "\n rating: " << movie->getRating() << "\n";	
      }
    }
  }
  std::cout << "---------------\n";
}

void deleteMedia(std::vector<Parent*>& database) { //given a title or year, choose whether to delete each matching object
  char input[10];
  char title[20];
  int year;
  bool field = TITLE; //search field
  std::cout << "Search field (TITLE/YEAR):\n";
  std::cin >> input;
  std::cout << "Search query:\n";
  if (strncmp(input, "TITLE", 5) == 0) { //take in title
    std::cin.get(title, 19);
  }
  if (strncmp(input, "YEAR", 4) == 0) { //take in year
    std::cin >> year;
    field = YEAR;
  }

  for (std::vector<Parent*>::iterator it = database.begin(); it != database.end();) {
    if ((!field && strcmp((*it)->getTitle(),title) == 0) //title search
	|| field && (*it)->getYear() == year) { //year search
      std::cout << "Would you like to delete this object? (y/n)\n---------------\n"
		<<(*it)->getType() << " \n title: " << (*it)->getTitle() << " \n year: " << (*it)->getYear()
		<< "\n----------------\n"; 
      char ans; //user response
      std::cin >> ans;
      if (ans == 'y') { 
	delete (*it); //call destructor on object
	it = database.erase(it); //delete from vector, iterator is reassigned and moves forward
	std::cout << "The item has been removed.\n";
	continue;
      }
    }
    ++it; //move forward if nothing is deleted
  }
}

int main() {
  std::vector<Parent*> database;
  bool running = true;
  char input[10];
  
  while (running) {
    std::cout << "Enter your command (ADD, SEARCH, DELETE):\n";
    std::cin >> input;
    if (strncmp(input, "ADD", 3) == 0) {
      addMedia(database);
    }
    if (strncmp(input, "SEARCH", 6) == 0) {
      searchMedia(database);      
    }
    if (strncmp(input, "DELETE", 6) == 0) {
      deleteMedia(database);
    }
    if (strncmp(input, "QUIT", 4) == 0) { //quit and delete all remaining objects
      for (std::vector<Parent*>::iterator it = database.begin(); it != database.end(); ++it) {
	delete (*it);
      }
      running = false;
    }
  }
  return 0;
}
