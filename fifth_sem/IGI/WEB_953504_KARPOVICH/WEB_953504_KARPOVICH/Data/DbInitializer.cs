using Microsoft.AspNetCore.Identity;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using WEB_953504_KARPOVICH.Entities;

namespace WEB_953504_KARPOVICH.Data
{
    public class DbInitializer
    {
        public static async Task Seed(ApplicationDbContext context, UserManager<ApplicationUser> userManager,
            RoleManager<IdentityRole> roleManager)
        {
            // create a database if it has not been created yet
            context.Database.EnsureCreated();
            // checking for roles
            if (!context.Roles.Any())
            {
                var roleAdmin = new IdentityRole
                {
                    Name = "admin",
                    NormalizedName = "admin"
                };
                // create admin role
                await roleManager.CreateAsync(roleAdmin);
            }
            // checking the availability of users
            if (!context.Users.Any())
            {
                // create user user@mail.ru
                var user = new ApplicationUser
                {
                    Email = "user@mail.ru",
                    UserName = "user@mail.ru"
                };
                await userManager.CreateAsync(user, "123456");
                // create user admin@mail.ru
                var admin = new ApplicationUser
                {
                    Email = "admin@mail.ru",
                    UserName = "admin@mail.ru"
                };
                await userManager.CreateAsync(admin, "123456");
                // assign role admin
                admin = await userManager.FindByEmailAsync("admin@mail.ru");
                await userManager.AddToRoleAsync(admin, "admin");
            }

            // checking for the presence of groups of objects
            if (!context.Brands.Any())
            {
                context.Brands.AddRange(
                new List<Brand>
            {
                 new Brand {BrandName="HP"},
                 new Brand {BrandName="Apple"},
                 new Brand {BrandName="Samsung"},
                 new Brand {BrandName="Asus"},
                 new Brand {BrandName="Honor"},
                 new Brand {BrandName="Huaweui"}
            });
            }
            // check for the presence of objects
            if (!context.Notebooks.Any())
            {
                context.Notebooks.AddRange(
                    new List<Notebook>
            {
                new Notebook {NotebookName="ASUS TUF Gaming Dash",
                    Description="Good new notebook of 2021 year",
                    Price=3255, BrandId=4, Image="asus-tuf-gaming.jpeg" },

                new Notebook {NotebookName="ASUS X515EA",
                    Description="Brand-new notebook from popular 'Asus' brand",
                    Price=1180, BrandId=4, Image="asus-x15.jpeg" },

                new Notebook {NotebookName="HONOR MagicBook X15",
                    Description="Powerful, stylish, cheap", Price=1630, BrandId=5, Image="honor-magic-book.jpeg" },

                new Notebook {NotebookName="HP 15s-eq", Description="Convenient notebook for a good price",
                    Price=1429, BrandId=1, Image="hp-15s.jpeg" },

                new Notebook {NotebookName="Apple Macbook Pro 14",
                    Description="Very powerfull notebook, but the price is high",
                    Price=7300, BrandId=2, Image="macbook-pro-14.jpeg" },

                new Notebook {NotebookName="Apple Macbook Air 13",
                    Description="Light-weight notebook for all spheres of life",
                    Price=2750, BrandId=2, Image="macbook-air-13.jpeg" }
            });

                await context.SaveChangesAsync();
            }
        }
    }
}
