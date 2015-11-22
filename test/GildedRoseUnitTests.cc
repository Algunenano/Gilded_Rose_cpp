#include <gtest/gtest.h>

#include "GildedRose.h"

TEST(GildedRoseTest, Item_maintains_name) {
    vector<Item> items;
    items.push_back(Item("Default", 10, 20));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Default", app.items[0].name);
}

TEST(GildedRoseTest, Item_default_decreases_sellin_n_quality) {
    vector<Item> items;
    items.push_back(Item("Default", 10, 20));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(9, app.items[0].sellIn);
    EXPECT_EQ(19, app.items[0].quality);
}

TEST(GildedRoseTest, Item_default_decreases_sellin_n_quality_twice_when_sellin) {
    vector<Item> items;
    items.push_back(Item("Default", 0, 20));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(-1, app.items[0].sellIn);
    EXPECT_EQ(18, app.items[0].quality);
}

TEST(GildedRoseTest, Item_default_quality_loss_stops_at_0) {
    vector<Item> items;
    items.push_back(Item("Default", 0, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(-1, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseTest, Cheese_maintain_name) {
    vector<Item> items;
    items.push_back(Item("Aged Brie", 2, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ("Aged Brie", app.items[0].name);
}

TEST(GildedRoseTest, Cheese_decreases_sellin) {
    vector<Item> items;
    items.push_back(Item("Aged Brie", 2, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(1, app.items[0].sellIn);
}

TEST(GildedRoseTest, Cheese_increases_quality) {
    vector<Item> items;
    items.push_back(Item("Aged Brie", 2, 0));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(1, app.items[0].quality);
}

TEST(GildedRoseTest, Cheese_increases_quality_upto50) {
    vector<Item> items;
    items.push_back(Item("Aged Brie", 0, 50));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(50, app.items[0].quality);
}

TEST(GildedRoseTest, Cheese_increases_twice_passed_selldate) {
    vector<Item> items;
    items.push_back(Item("Aged Brie", -2, 20));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(-3, app.items[0].sellIn);
    EXPECT_EQ(22, app.items[0].quality);
}

TEST(GildedRoseTest, Sulfuras_never_sold_nor_decreases_quality) {
    vector<Item> items;
    items.push_back(Item("Sulfuras, Hand of Ragnaros", -5, 80));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(-5, app.items[0].sellIn);
    EXPECT_EQ(80, app.items[0].quality);
}

TEST(GildedRoseTest, Sulfuras_never_sold_nor_decreases_quality2) {
    vector<Item> items;
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 60, 80));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(60, app.items[0].sellIn);
    EXPECT_EQ(80, app.items[0].quality);
}

TEST(GildedRoseTest, Backstage_increases_more_than10) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 50, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(49, app.items[0].sellIn);
    EXPECT_EQ(11, app.items[0].quality);
}

TEST(GildedRoseTest, Backstage_increases_more_than10_2) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 11, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(10, app.items[0].sellIn);
    EXPECT_EQ(11, app.items[0].quality);
}

TEST(GildedRoseTest, Backstage_increases_bt_5_n_10) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 8, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(7, app.items[0].sellIn);
    EXPECT_EQ(12, app.items[0].quality);
}

TEST(GildedRoseTest, Backstage_increases_5) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 5, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(4, app.items[0].sellIn);
    EXPECT_EQ(13, app.items[0].quality);
}

TEST(GildedRoseTest, Backstage_increases_1) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 1, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(0, app.items[0].sellIn);
    EXPECT_EQ(13, app.items[0].quality);
}

TEST(GildedRoseTest, Backstage_increases_0) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 0, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(-1, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}

TEST(GildedRoseTest, Backstage_increases_after) {
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", -5, 10));
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(-6, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);
}