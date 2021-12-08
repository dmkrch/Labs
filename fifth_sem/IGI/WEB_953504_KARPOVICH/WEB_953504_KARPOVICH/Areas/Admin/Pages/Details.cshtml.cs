using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Microsoft.EntityFrameworkCore;
using WEB_953504_KARPOVICH.Data;
using WEB_953504_KARPOVICH.Entities;

namespace WEB_953504_KARPOVICH.Areas.Admin.Pages
{
    public class DetailsModel : PageModel
    {
        private readonly WEB_953504_KARPOVICH.Data.ApplicationDbContext _context;

        public DetailsModel(WEB_953504_KARPOVICH.Data.ApplicationDbContext context)
        {
            _context = context;
        }

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
            return Page();
        }
    }
}
