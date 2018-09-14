//
// Created by KutiHe on 18-9-13.
//

#ifndef CTLIB_CT_TUPLE_H
#define CTLIB_CT_TUPLE_H

#include <cstddef>
#include "_HeaderCore.h"
CTTUPLE
template<size_t value,class ... Args>
struct _ct_tuple_class;
template<class ... AllTypes>
class ct_tuple;
template<size_t value,class _This,class ... _Other>
using _ct_tuple_type = typename _ct_tuple_class<value,ct_tuple<_This,_Other...>>::_ClassTy;
template<class _This>
        class ct_tuple<_This>{                                  //std layout
        public:
            template<class _this>
            constexpr ct_tuple(_this arg):member(arg){}
            constexpr size_t getSize()const {
                return size;
            }
        private:
            using _ThisTy = _This;
            _This member;
            const size_t size = 1;
            using Type = ct_tuple<_This>;



            template<class ... _Types>
                    friend
                    struct _CORE::_BaseName;
            template<size_t value,class _this,class ... _other>
                    friend
                    inline typename _ct_tuple_type<value,_this,_other...>::_ThisTy get(ct_tuple<_this,_other...> arg);
        };
template<class _This,class ... _Other>
        class ct_tuple<_This,_Other...>:
                public ct_tuple<_Other...>
        {
        public:
            template<class _this,class ... _other>
            constexpr ct_tuple(_this arg,_other ... other):member(arg),ct_tuple<_Other...>(other...){}
            constexpr size_t getSize()const {
                return size;
            }
        private:
            using _ThisTy = _This;
            _This member;
            const size_t size = sizeof...(_Other) + 1;
            using Type = ct_tuple<_This,_Other...>;



            template<class ... _Types>
                    friend
                    struct _CORE::_BaseName;
            template<size_t value,class _this,class ... _other>
                    friend
                    inline typename _ct_tuple_type<value,_this,_other...>::_ThisTy get(ct_tuple<_this,_other...> arg);
        };
ENDL
template<class _This,class ... _Other>
struct _CORE::_BaseName<CTL::ct_tuple<_This,_Other...>> {
    using _Type =typename CTL::ct_tuple<_This,_Other...>::Type;
};
CTTUPLE
    template<class _This,class ... _Other>
    struct _ct_tuple_class<0,ct_tuple<_This,_Other...>>{
        using _ClassTy = typename _CORE::_BaseName<ct_tuple<_This,_Other...>>::_Type;
    };

    template<size_t value,class _This,class ... _Other>
    struct _ct_tuple_class<value,ct_tuple<_This,_Other...>>
            :public _ct_tuple_class<value - 1,ct_tuple<_Other...>>{

    };
    template<size_t value,class _this,class ... _other>
    inline typename _ct_tuple_type<value,_this,_other...>::_ThisTy get(ct_tuple<_this,_other...> arg){
        return arg._ct_tuple_type<value,_this,_other...>::member;
    }
ENDL
#endif //CTLIB_CT_TUPLE_H
