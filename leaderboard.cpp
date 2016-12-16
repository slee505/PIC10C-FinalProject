#include "leaderboard.h"
#include "ui_leaderboard.h"

extern MainWindow * game;

leaderboard::leaderboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::leaderboard)
{
    ui->setupUi(this);
    //sort scores from the scores txt file
    sortScore();
    //opens file of sorted scores
    QFile scores("sorted.txt");

    if(!scores.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Error", "Something went wrong with the input");
    }
    
    //Add scores from text file into the list widget
    QTextStream in(&scores);
    int i = 0;
    while(!in.atEnd() && i < 20)
       {
          QString line = in.readLine();
          ui->listWidget->addItem(line);
          ++i;
       }

    scores.close();

}

leaderboard::~leaderboard()
{
        delete ui;
    }

void leaderboard::sortScore()
{
  //create vector of name and score pairs
  std::vector<std::pair<std::string,int>> entries;
  std::ifstream sortStream("scores.txt");
  int score;
  std::string name;
  //input name and score from the scores text file into the vector
  while(sortStream >> name >> score){
      std::pair<std::string,int> entry = std::make_pair(name, score);
      entries.push_back(entry);
   }
  //sort the vector
  std::sort(entries.begin(), entries.end(), [](const std::pair<std::string,int> &left, const std::pair<std::string,int> &right){return left.second < right.second;});
  std::reverse(entries.begin(),entries.end());

  //input the sorted vector values into a new text file
  QFile scores("sorted.txt");

   if(!scores.open(QFile::WriteOnly | QFile::Text)){
       QMessageBox::warning(this, "Error", "Something went wrong with the input");
   }
   QTextStream out(&scores);
   for(size_t i = 0; i < entries.size(); ++i){
       QString qname = QString::fromStdString(entries.at(i).first);
       out << qname << " " << entries.at(i).second << "\n";
   }
   scores.flush();
   scores.close();
}

//Go back to main menu when button is clicked
void leaderboard::on_pushButton_clicked()
{
    game = new MainWindow();
    game->show();
    hide();
}
