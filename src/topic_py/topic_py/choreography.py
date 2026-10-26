import tkinter as tk
from tkinter import ttk, filedialog, messagebox
import json
import os

class choreography:
    def __init__(self, root):
        self.root = root
        self.root.title("JSON 文件编辑器")
        self.root.geometry("800x600")

        # 当前文件路径
        self.current_file = None

        # 创建界面
        self.create_widgets()

    def create_widgets(self):
        # 创建菜单栏
        self.create_menu()

        # 创建主框架
        main_frame = ttk.Frame(self.root, padding="10")
        main_frame.pack(fill=tk.BOTH, expand=True)

        # 按钮框架
        button_frame = ttk.Frame(main_frame)
        button_frame.pack(fill=tk.X, pady=(0, 10))

        # 按钮
        self.load_btn = ttk.Button(button_frame, text="导入 JSON", command=self.load_json)
        self.load_btn.pack(side=tk.LEFT, padx=(0, 10))

        self.save_btn = ttk.Button(button_frame, text="保存", command=self.save_json)
        self.save_btn.pack(side=tk.LEFT, padx=(0, 10))

        self.save_as_btn = ttk.Button(button_frame, text="另存为", command=self.save_as_json)
        self.save_as_btn.pack(side=tk.LEFT, padx=(0, 10))

        self.add_btn = ttk.Button(button_frame, text="添加项", command=self.add_item)
        self.add_btn.pack(side=tk.LEFT, padx=(0, 10))

        self.delete_btn = ttk.Button(button_frame, text="删除项", command=self.delete_item)
        self.delete_btn.pack(side=tk.LEFT)

        # 状态标签
        self.status_label = ttk.Label(button_frame, text="未加载文件")
        self.status_label.pack(side=tk.RIGHT)

        # 创建Treeview来显示JSON数据
        self.create_treeview(main_frame)

        # 编辑框架
        self.create_edit_area(main_frame)

    def create_menu(self):
        menubar = tk.Menu(self.root)
        self.root.config(menu=menubar)

        # 文件菜单
        file_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="文件", menu=file_menu)
        file_menu.add_command(label="打开", command=self.load_json)
        file_menu.add_command(label="保存", command=self.save_json)
        file_menu.add_command(label="另存为", command=self.save_as_json)
        file_menu.add_command(label="属性", command=self.show_properties)
        file_menu.add_separator()
        file_menu.add_command(label="退出", command=self.root.quit)

        # 编辑菜单
        edit_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="编辑", menu=edit_menu)
        edit_menu.add_command(label="添加项", command=self.add_item)
        edit_menu.add_command(label="删除项", command=self.delete_item)

    # 在 class choreography 中添加如下方法
    def show_properties(self):
        # 检查当前json文件字典中里的名字，作者属性
        if self.current_file:
            props = f"文件路径: {self.current_file}\n文件名: {os.path.basename(self.current_file)}"
            messagebox.showinfo("文件属性", props)
        else:
            messagebox.showwarning("警告", "当前没有加载任何文件")

    def create_treeview(self, parent):
        # 创建框架包含Treeview和滚动条
        tree_frame = ttk.Frame(parent)
        tree_frame.pack(fill=tk.BOTH, expand=True)

        # 创建Treeview
        self.tree = ttk.Treeview(tree_frame, columns=("value"), show="tree headings")
        self.tree.heading("#0", text="键")
        self.tree.heading("value", text="值")

        # 设置列宽
        self.tree.column("#0", width=200)
        self.tree.column("value", width=400)

        # 滚动条
        v_scrollbar = ttk.Scrollbar(tree_frame, orient=tk.VERTICAL, command=self.tree.yview)
        h_scrollbar = ttk.Scrollbar(tree_frame, orient=tk.HORIZONTAL, command=self.tree.xview)
        self.tree.configure(yscrollcommand=v_scrollbar.set, xscrollcommand=h_scrollbar.set)

        # 布局
        self.tree.grid(row=0, column=0, sticky="nsew")
        v_scrollbar.grid(row=0, column=1, sticky="ns")
        h_scrollbar.grid(row=1, column=0, sticky="ew")

        tree_frame.grid_rowconfigure(0, weight=1)
        tree_frame.grid_columnconfigure(0, weight=1)

        # 绑定选择事件
        self.tree.bind("<<TreeviewSelect>>", self.on_item_select)
        self.tree.bind("<Double-1>", self.on_item_double_click)

    def create_edit_area(self, parent):
        # 编辑区域框架
        edit_frame = ttk.LabelFrame(parent, text="编辑选中项", padding="10")
        edit_frame.pack(fill=tk.X, pady=(10, 0))

        # 键输入
        ttk.Label(edit_frame, text="键:").grid(row=0, column=0, sticky=tk.W, padx=(0, 10))
        self.key_var = tk.StringVar()
        self.key_entry = ttk.Entry(edit_frame, textvariable=self.key_var, width=30)
        self.key_entry.grid(row=0, column=1, sticky=tk.W, padx=(0, 20))

        # 值输入
        ttk.Label(edit_frame, text="值:").grid(row=1, column=0, sticky=tk.W, padx=(0, 10))
        self.value_text = tk.Text(edit_frame, width=50, height=4)
        self.value_text.grid(row=1, column=1, sticky=tk.W, pady=(5, 0))

        # 更新按钮
        self.update_btn = ttk.Button(edit_frame, text="更新项", command=self.update_item)
        self.update_btn.grid(row=2, column=1, sticky=tk.W, pady=(10, 0))

        # 当前选中的项
        self.selected_item = None

    def load_json(self):
        file_path = filedialog.askopenfilename(
            title="选择 JSON 文件",
            filetypes=[("JSON 文件", "*.json"), ("所有文件", "*.*")]
        )

        if file_path:
            try:
                with open(file_path, 'r', encoding='utf-8') as file:
                    data = json.load(file)

                self.current_file = file_path
                self.display_json(data)
                self.status_label.config(text=f"已加载: {os.path.basename(file_path)}")

            except Exception as e:
                messagebox.showerror("错误", f"加载文件时出错:\n{str(e)}")

    def display_json(self, data, parent="", key=""):
        # 清空现有数据
        for item in self.tree.get_children():
            self.tree.delete(item)

        # 递归显示JSON数据
        self._add_tree_items("", data)

    def _add_tree_items(self, parent, data):
        if isinstance(data, dict):
            for key, value in data.items():
                item_id = self.tree.insert(parent, "end", text=str(key), values=(
                    str(value) if not isinstance(value, (dict, list)) else f"{type(value).__name__}"))
                if isinstance(value, (dict, list)):
                    self._add_tree_items(item_id, value)
        elif isinstance(data, list):
            for i, value in enumerate(data):
                item_id = self.tree.insert(parent, "end", text=str(i), values=(
                    str(value) if not isinstance(value, (dict, list)) else f"{type(value).__name__}"))
                if isinstance(value, (dict, list)):
                    self._add_tree_items(item_id, value)
        else:
            self.tree.insert(parent, "end", text=parent, values=(str(data)))

    def on_item_select(self, event):
        selection = self.tree.selection()
        if selection:
            self.selected_item = selection[0]
            item_text = self.tree.item(self.selected_item, "text")
            item_values = self.tree.item(self.selected_item, "values")

            self.key_var.set(item_text)
            self.value_text.delete(1.0, tk.END)
            if item_values:
                self.value_text.insert(1.0, item_values[0])

    def on_item_double_click(self, event):
        # 双击展开/折叠
        item = self.tree.identify_row(event.y)
        if item:
            if self.tree.item(item, "open"):
                self.tree.item(item, open=False)
            else:
                self.tree.item(item, open=True)

    def update_item(self):
        if not self.selected_item:
            messagebox.showwarning("警告", "请先选择一个项")
            return

        new_key = self.key_var.get()
        new_value = self.value_text.get(1.0, tk.END).strip()

        if not new_key:
            messagebox.showwarning("警告", "键不能为空")
            return

        # 更新Treeview
        self.tree.item(self.selected_item, text=new_key, values=(new_value,))

        messagebox.showinfo("成功", "项已更新")

    def add_item(self):
        # 简单的添加功能 - 添加到根级
        new_key = simpledialog.askstring("添加项", "请输入键名:")
        if new_key:
            new_value = simpledialog.askstring("添加项", "请输入值:")
            if new_value is not None:
                self.tree.insert("", "end", text=new_key, values=(new_value,))

    def delete_item(self):
        if not self.selected_item:
            messagebox.showwarning("警告", "请先选择一个项")
            return

        if messagebox.askyesno("确认", "确定要删除这个项吗?"):
            self.tree.delete(self.selected_item)
            self.selected_item = None
            self.key_var.set("")
            self.value_text.delete(1.0, tk.END)

    def save_json(self):
        if not self.current_file:
            self.save_as_json()
            return

        try:
            data = self.tree_to_dict()
            with open(self.current_file, 'w', encoding='utf-8') as file:
                json.dump(data, file, ensure_ascii=False, indent=4)

            messagebox.showinfo("成功", f"文件已保存: {self.current_file}")

        except Exception as e:
            messagebox.showerror("错误", f"保存文件时出错:\n{str(e)}")

    def save_as_json(self):
        file_path = filedialog.asksaveasfilename(
            title="保存 JSON 文件",
            defaultextension=".json",
            filetypes=[("JSON 文件", "*.json"), ("所有文件", "*.*")]
        )

        if file_path:
            self.current_file = file_path
            self.save_json()
            self.status_label.config(text=f"已保存: {os.path.basename(file_path)}")

    def tree_to_dict(self):
        # 将Treeview数据转换回字典
        # 这是一个简化的实现，实际应用中可能需要更复杂的逻辑来处理嵌套结构
        data = {}
        for child in self.tree.get_children():
            key = self.tree.item(child, "text")
            values = self.tree.item(child, "values")
            if values:
                data[key] = values[0]
        return data


# 为了使用simpledialog，需要导入
from tkinter import simpledialog

if __name__ == "__main__":
    root = tk.Tk()
    app = choreography(root)
    root.mainloop()