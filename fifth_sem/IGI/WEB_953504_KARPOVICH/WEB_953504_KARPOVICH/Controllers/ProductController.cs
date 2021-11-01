using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using WEB_953504_KARPOVICH.Data;
using WEB_953504_KARPOVICH.Entities;
using WEB_953504_KARPOVICH.Models;

namespace WEB_953504_KARPOVICH.Controllers
{
    public class ProductController : Controller
    {
        List<Notebook> _notebooks;
        List<Brand> _brands;

        int _pageSize;
        public ProductController()
        {
            _pageSize = 3;
            SetupData();
        }
        public IActionResult Index(int? group, int pageNo = 1)
        {
            var notebooksFiltered = _notebooks.Where(d => !group.HasValue || d.BrandId == group.Value);
            // Поместить список групп во ViewData
            ViewData["Groups"] = _brands;
            // Получить id текущей группы и поместить в TempData
            ViewData["CurrentGroup"] = group ?? 0;

            return View(ListViewModel<Notebook>.GetModel(notebooksFiltered, pageNo, _pageSize));
        }

        /// <summary>
        /// Инициализация списков
        /// </summary>
        private void SetupData()
        {
            _brands = new List<Brand>
            {
                 new Brand {BrandId=1, BrandName="HP"},
                 new Brand {BrandId=2, BrandName="Apple"},
                 new Brand {BrandId=3, BrandName="Samsung"},
                 new Brand {BrandId=4, BrandName="Asus"},
                 new Brand {BrandId=5, BrandName="Honor"},
                 new Brand {BrandId=6, BrandName="Huaweui"}
            };

            _notebooks = new List<Notebook>
            {
                new Notebook {NotebookId=1, NotebookName="ASUS TUF Gaming Dash",
                    Description="Good new notebook of 2021 year",
                    Price=3255, BrandId=4, Image="asus-tuf-gaming.jpeg" },

                new Notebook {NotebookId=2, NotebookName="ASUS X515EA", 
                    Description="Brand-new notebook from popular 'Asus' brand",
                    Price=1180, BrandId=4, Image="asus-x15.jpeg" },

                new Notebook {NotebookId=3, NotebookName="HONOR MagicBook X15", 
                    Description="Powerful, stylish, cheap", Price=1630, BrandId=5, Image="honor-magic-book.jpeg" },

                new Notebook {NotebookId=4, NotebookName="HP 15s-eq", Description="Convenient notebook for a good price",
                    Price=1429, BrandId=1, Image="hp-15s.jpeg" },

                new Notebook {NotebookId=5, NotebookName="Apple Macbook Pro 14",
                    Description="Very powerfull notebook, but the price is high",
                    Price=7300, BrandId=2, Image="macbook-pro-14.jpeg" },

                new Notebook {NotebookId=6, NotebookName="Apple Macbook Air 13",
                    Description="Light-weight notebook for all spheres of life",
                    Price=2750, BrandId=2, Image="macbook-air-13.jpeg" }
            };
        }
    }
}
