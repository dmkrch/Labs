using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using WEB_953504_KARPOVICH.Data;
using WEB_953504_KARPOVICH.Entities;

namespace WEB_953504_KARPOVICH.Areas.Admin.Pages
{
    public class CreateModel : PageModel
    {
        private readonly WEB_953504_KARPOVICH.Data.ApplicationDbContext _context;

        public CreateModel(WEB_953504_KARPOVICH.Data.ApplicationDbContext context)
        {
            _context = context;
        }

        public IActionResult OnGet()
        {
        ViewData["BrandId"] = new SelectList(_context.Brands, "BrandId", "BrandName");
            return Page();
        }

        [BindProperty]
        public Notebook Notebook { get; set; }

        // To protect from overposting attacks, see https://aka.ms/RazorPagesCRUD
        public async Task<IActionResult> OnPostAsync()
        {
            if (!ModelState.IsValid)
            {
                return Page();
            }

            _context.Notebooks.Add(Notebook);
            await _context.SaveChangesAsync();

            return RedirectToPage("./Index");
        }
    }
}
