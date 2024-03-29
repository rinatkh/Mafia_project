#ifndef MAINFRAGMENT_H
#define MAINFRAGMENT_H

#include "abstractfragment.h"
#include "screensfactory.h"
#include "client_impl.h"


#include <QPushButton>
#include <QInputDialog>
#include <QLabel>

class MainFragment: public AbstractFragment {
    Q_OBJECT

public:
    MainFragment();
    ~MainFragment();
public slots:
    void onCreatePressed();
    void onPlayPressed();
    void onOptionsPressed();
    void onNetError();
    void onCreated(int id);
    void onJoined(int id);

private:
    QPushButton *createButton;
    QPushButton *playButton;
    QPushButton *optionsButton;
    QLabel *statusLabel;
};

#endif // MAINFRAGMENT_H
