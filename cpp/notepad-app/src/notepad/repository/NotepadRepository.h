#include <vector>

using  std::vector;

class NotepadRepository {
public:
    virtual void save(Note note) = 0;

    virtual void remove(int id) = 0;

    virtual Note findOne(int id) = 0;

    virtual vector<Note> findAll() = 0;

    virtual bool existsById(int id) = 0;

    virtual void init() = 0;

    virtual void destroy() = 0;

};



