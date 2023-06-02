#include <gtest/gtest.h>
#include "list_container.cpp"


TEST(List_Container, correctCreation_list) {
    List_Container_oneDir <int> con1;
    //проверяем, что контейнер в начале имеет нулевой размер
    ASSERT_EQ( con1.size(), 0) ;
    //Исключение, если размер нулевой
    ASSERT_ANY_THROW(con1.createCont(0));
    //Исключение, если размер отрицательный
    ASSERT_ANY_THROW(con1.createCont(-50));
    //создаем массив на кол-во элементов, превышающее минимальную память
    con1.createCont(25);
    //размер должен стать 25
    ASSERT_EQ( con1.size(), 25) ;
}


TEST(List_Container, checkGetByInd_list) {
    List_Container_oneDir <int> con1;
    con1.createCont(10);
    for (int i=0; i<10; ++i) {
         ASSERT_EQ( con1[i], i) ;
    }
}

TEST(List_Container, checkInsert_neg_list) {
    List_Container_oneDir <int> con1;
    con1.createCont(10);
    //добавить в отрицательный индекс
    ASSERT_ANY_THROW( con1.insert(-1, 1));
}

TEST(List_Container, checkInsert_nonExistent_list) {
    List_Container_oneDir <int> con1;
    con1.createCont(10);
    //добавить в несуществующий индекс
    ASSERT_ANY_THROW( con1.insert(10000, 1));
}

TEST(List_Container, checkInsert_middle_list) {
    List_Container_oneDir <int> con1;
    con1.createCont(10);
    //добавить в существующий индекс
    con1.insert(5, 0xA);
    //проверить, что 5ый элемент 0xA
    ASSERT_EQ( con1[5], 0xA) ;
    //размер должен стать 11
    ASSERT_EQ( con1.size(), 11) ;
}


TEST(List_Container, checkInsert_beg_list) {
    List_Container_oneDir <int> con1;
    con1.createCont(10);
    //добавить в начало
    con1.insert(0, 0xB);
    //проверить, что 0ой элемент 0xB
    ASSERT_EQ( con1[0], 0xB) ;
    //размер должен стать 11
    ASSERT_EQ( con1.size(), 11) ;
}

TEST(List_Container, checkInsert_end_list) {
    List_Container_oneDir <int> con1;
    con1.createCont(10);
    //добавить в конец
    con1.insert(10, 0xC);
    //проверить, что последний элемент 0xС
    ASSERT_EQ( con1[10], 0xC) ;
    //размер должен стать 11
    ASSERT_EQ( con1.size(), 11);
}

TEST(List_Container, checkErase_neg_list) {
    List_Container_oneDir <int> con1;
    con1.createCont(10);
    //удалить отрицательный индекс
    ASSERT_ANY_THROW( con1.erase(-1));
}

TEST(List_Container, checkErase_nonExistent_list) {
    List_Container_oneDir <int> con1;
    con1.createCont(10);
    //удалить несуществующий индекс
    ASSERT_ANY_THROW( con1.erase(25));
}

TEST(List_Container, checkErase_beg_list) {
    List_Container_oneDir <int> con1;
    con1.createCont(10);
    //удалить нулевой индекс
    con1.erase(0);
    //проверить, что 0й элемент 1
    ASSERT_EQ(con1[0], 1) ;
    //размер должен стать 9
    ASSERT_EQ( con1.size(), 9) ;
}

TEST(List_Container, checkErase_middle_list) {
    List_Container_oneDir <int> con1;
    con1.createCont(10);
    //удалить индекс 7
    con1.erase(7);
    //проверить, что 7ой элемент 8
    ASSERT_EQ( con1[7], 0x8) ;
    //размер должен стать 9
    ASSERT_EQ( con1.size(), 9) ;
}

TEST(List_Container, checkErase_end_list) {
    List_Container_oneDir <int> con1;
    con1.createCont(10);
    //удалить последний индекс
    con1.erase(9);
    //размер должен стать 9
    ASSERT_EQ( con1.size(), 9) ;
}


TEST(List_Container, checkErase_empty_list) {
    List_Container_oneDir <int> con1;
    con1.createCont(2);
    con1.erase(1);
    ASSERT_EQ( con1.size(), 1) ;
    con1.erase(0);
    ASSERT_EQ( con1.size(), 0) ;
    ASSERT_ANY_THROW( con1.erase(0));
}

TEST(List_Container, checkCopy_list) {
     List_Container_oneDir <int> con1;
     con1.createCont(5);
     List_Container_oneDir<int> con2 = con1;
     ASSERT_EQ( con1.size(), con2.size()) ;
     for (size_t i=0; i<con1.size(); ++i) {
         ASSERT_EQ( con2[i], i) ;
     }
}

TEST(List_Container, checkMove_Constr_list) {
     List_Container_oneDir <int> con1;
     con1.createCont(5);
     List_Container_oneDir <int> moveCon = std::move(con1);
     ASSERT_EQ( moveCon.size(), 5) ;
     for (size_t i=0; i<moveCon.size(); ++i) {
         ASSERT_EQ( moveCon[i], i) ;
     }
     ASSERT_EQ( con1.size(), 0) ;
}

TEST(List_Container, checkMove_Operator_list) {
     List_Container_oneDir <int> con1;
     con1.createCont(5);
     List_Container_oneDir <int> moveCon;
     moveCon = std::move(con1);
     ASSERT_EQ( moveCon.size(), 5) ;
     for (size_t i=0; i<moveCon.size(); ++i) {
         ASSERT_EQ( moveCon[i], i) ;
     }
     ASSERT_EQ( con1.size(), 0) ;
}

//TEST(Sequence_Container, checkDelete) {
//     Sequence_Container <int> con1;
//     con1.createCont(5);
//     Sequence_Container <int> moveCon;
//     moveCon = std::move(con1);
//     ASSERT_EQ( moveCon.size(), 5) ;
//     for (size_t i=0; i<moveCon.size(); ++i) {
//         ASSERT_EQ( moveCon[i], i) ;
//     }
//     ASSERT_EQ( con1.size(), 0) ;
//}
