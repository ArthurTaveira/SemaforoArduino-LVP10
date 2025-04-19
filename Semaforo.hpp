#ifndef SEMAFORO_HPP
#define SEMAFORO_HP

class Semaforo {
  private:
    int luzVermelha;
    int luzAmarela;
    int luzVerde;
  public:
    Semaforo(int luzVermelha, int luzAmarela, int luzVerde);
    void ligar();
    void desligar();
    void temporizar(int segundos);
    void acenderPare();
    void acenderAtencao();
    void acenderSiga();
};

#endif
