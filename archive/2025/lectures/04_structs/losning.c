typedef struct {
    int dag;
    int aar;
    int maaned;
    bool kjonn;
    int alder;
} person_t;


person_t legg_til_person(int dag, int maaned, int aar, int individnr, int kontrollnr) {
    person_t ret = {0};
    ret.dag = dag;
    ret.aar = aar;
    ret.maaned = maaned;
    ret.kjonn = (individnr / 10) % 2 == 0;
    ret.alder = 2025 - aar;
    return ret;
}
