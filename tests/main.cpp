//
// Created by sacha on 09-12-22.
//

int main(){

    auto b=make_shared<Board>(); //Model
    Ui ui{b};
    Controller controller{b};

    while(true)
    {
        ui.display();

    }
}
