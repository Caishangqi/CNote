#include <iostream>
#include <string>
#include <memory>

class Entity
{
public:
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void Print()
    {
    }
};

int main(int argc, char* argv[])
{
    /*use unique pointer*/
    {
        /*unique pointer 默认 explict 你没法用 new Entity()*/
        std::unique_ptr<Entity> entity(new Entity());
        /*推荐方法为*/
        std::unique_ptr<Entity> entityG = std::make_unique<Entity>(); //safer

        entity->Print();
    }

    /* use shared pointer (make by reference counting- keep track how many reference you have)
     * if i create 1 shared pointer reference 2, when first one dies, reference count minus 1,
     * when last one dies, reference counting goes to zero, memory gets freed
     */
    {
        std::shared_ptr<Entity> e0;

        {
            /*shared pointer would also allocated a block of memory called control block*/
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            //at this point it would increase the reference count
            e0 = sharedEntity; //reference count is 2
        } //在这行结尾不会被摧毁因为你讲 sharedEntity指向 e0
    }

    /* use weight pointer*/
    {
        std::weak_ptr<Entity> e0;
        {
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); // reference count = 1
            /* weak_ptr would not create the reference count hence reference count = 1
             * when you assign a shared pointer to weak pointer, it won't increase ref count.
             */
            e0 = sharedEntity; // ity will destroy e0 at end of this scope
        }
        /* at now weak pointer point a invalid memory, but you can ask his if he keep alive*/
    }

    std::cin.get();
}
