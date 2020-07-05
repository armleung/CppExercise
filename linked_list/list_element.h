template <class T>
class ListElement {
    public:
        ListElement(const T &value) :next_(nullptr), data_(value) {}
        ~ListElement(){}

        const T &GetData() const { return data_;}
        ListElement<T> *GetNext() const {return next_;}
        void SetData(const T &value) { data_ = value; }
        void SetNext(ListElement<T>* elem) { next_ = elem;}
    private:
        T data_;
        ListElement<T> *next_;
};