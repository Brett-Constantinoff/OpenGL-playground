#ifndef VERTEXARRAYOBJECT_H
#define VERTEXARRAYOBJECT_H

    class VertexArrayObject{
        private:
            unsigned int id;

        public:
            void generate(unsigned int i);
            void bind(void);
            void enableAttribute(unsigned int i);
    };


#endif