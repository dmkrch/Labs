using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using WEB_953504_KARPOVICH.Data;
using WEB_953504_KARPOVICH.Entities;

namespace WEB_953504_KARPOVICH.Areas.Admin.Pages
{
    public class EditModel : PageModel
    {
        private readonly WEB_953504_KARPOVICH.Data.ApplicationDbContext _context;

        public EditModel(WEB_953504_KARPOVICH.Data.ApplicationDbContext context)
        {
            _context = context;
        }

        [BindProperty]
        public Notebook Notebook { get; set; }

        public async Task<IActionResult> OnGetAsync(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            Notebook = await _context.Notebooks
                .Include(n => n.Brand).FirstOrDefaultAsync(m => m.NotebookId == id);

            if (Notebook == null)
            {
                return NotFound();
            }
           ViewData["BrandId"] = new SelectList(_context.Brands, "BrandId", "BrandName");
            return Page();
        }

        // To protect from overposting attacks, enable the specific properties you want to bind to.
        // For more details, see https://aka.ms/RazorPagesCRUD.
        public async Task<IActionResult> OnPostAsync()
        {
            if (!ModelState.IsValid)
            {
                return Page();
            }

            _context.Attach(Notebook).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!NotebookExists(Notebook.NotebookId))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return RedirectToPage("./Index");
        }

        private bool NotebookExists(int id)
        {
            return _context.Notebooks.Any(e => e.NotebookId == id);
        }
    }
}
