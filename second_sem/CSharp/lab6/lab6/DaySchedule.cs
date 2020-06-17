﻿using System;
using System.Collections.Generic;
using System.Text;

namespace lab6
{
    class DaySchedule : ISchedule
    {
        public DaySchedule(List<Days> days)
        {
            daysOfWork = days;
            WorkTime = "Day";
        }

        public List<Days> daysOfWork { get; set; }

        public string WorkTime { get; set; }
    }
}
