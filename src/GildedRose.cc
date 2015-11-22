#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}

void updateDefault(Item& _item)
{
    _item.quality = max (_item.quality -1, 0);
    if (_item.sellIn <= 0)
    {
        _item.quality = max (_item.quality -1, 0);
    }
    
    _item.sellIn--;
}

void updateCheese(Item& _item)
{
    _item.quality = min (_item.quality +1, 50);
    if (_item.sellIn < 0)
    {
        _item.quality = min (_item.quality +1, 50);
    }
    
    _item.sellIn--;
}

void updateSulfuras(Item& _item)
{
    
}

void updateConcert(Item& _item)
{
    if (_item.sellIn > 10)
    {
        _item.quality++;
    } else {
        if (_item.sellIn > 5)
        {
            _item.quality += 2;
        } else {
            if (_item.sellIn > 0)
            {
                _item.quality += 3;
            } else {
                _item.quality = 0;
            }
        }
    }
    
    _item.sellIn--;
}

void GildedRose::updateQuality() 
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name == "Aged Brie") updateCheese(items[i]);
        else if (items[i].name == "Sulfuras, Hand of Ragnaros") updateSulfuras(items[i]);
        else if (items[i].name == "Backstage passes to a TAFKAL80ETC concert") updateConcert(items[i]);
        else updateDefault(items[i]);
    }     
}
