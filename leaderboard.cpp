#include "leaderboard.h"
#include "ui_leaderboard.h"

extern MainWindow * game;

leaderboard::leaderboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::leaderboard)
{
    ui->setupUi(this);

    sortScore();

    QFile scores("sorted.txt");

    if(!scores.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Error", "Something went wrong with the input");
    }
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
  std::vector<std::pair<std::string,int>> entries;
  std::ifstream sortStream("scores.txt");
  int score;
  std::string name;
  while(sortStream >> name >> score){
      std::pair<std::string,int> entry = std::make_pair(name, score);
      entries.push_back(entry);
   }
  std::sort(entries.begin(), entries.end(), [](const std::pair<std::string,int> &left, const std::pair<std::string,int> &right){return left.second < right.second;});
  std::reverse(entries.begin(),entries.end());

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

void leaderboard::on_pushButton_clicked()
{
    game = new MainWindow();
    game->show();
    hide();
}
